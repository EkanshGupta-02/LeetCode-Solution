//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string ans="";int sum=0;int c=0;
        for(int i=n-1;i>=0;i=i-2){
                    sum=arr[i]+arr[i-1]+c;
                    ans=to_string(sum%10)+ans;
                    c=sum/10;
        }
         if(c)ans=to_string(c)+ans;
         int i=0;while(i<ans.length() and ans[i]=='0')i++;
         if(ans.length()==i)return "0";
         return ans.substr(i);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends