//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int>a, int n) {
        // code here
        int missing=-1;
        int repeated=-1;
        for(int i=0;i<n;i++){
            if(a[abs(a[i])-1]<0)
                repeated=abs(a[i]);
            else
                a[abs(a[i])-1]=-a[abs(a[i])-1];
        }
        for(int i=0;i<n;i++){
            if(a[i]>0){
                missing=i+1;
                break;
            }
        }
        return {repeated,missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends