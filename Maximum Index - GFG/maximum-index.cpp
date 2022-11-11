//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
          vector<int> smallerArray (n, -1);
        vector<int> greaterArray (n, -1);
        smallerArray[0] = arr[0];
        greaterArray[n - 1] = arr[n - 1];
        for(int i = 1; i < n; i++){
            smallerArray[i] = min(smallerArray[i - 1], arr[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            greaterArray[i] = max(greaterArray[i + 1], arr[i]);
        }
        
        int low = 0;
        int high = 0;
        int ans = 0;
        while(low < n && high < n){
            if(smallerArray[low] <= greaterArray[high]){
                ans = max(ans, high - low);
                high++;
            }
            else{
                low++;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends