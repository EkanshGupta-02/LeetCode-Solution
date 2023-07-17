//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    vector<long long> distributeCandies(int n, int k) {
       int cnt = 0;
       vector<long long>ans(k,0);
       int idx = 0;
       
       int low = 0;
       int high = n;
       
       while(low<=high){
        long long int mid = (low + high) >> 1;
        long long int sum = (mid * (mid + 1)) >> 1;
        if (sum <= n) {
            cnt = mid / k;
            low = mid + 1;
        }
        else {
            high = mid - 1;
            }
        }
       
        int last = (cnt * k);
        n -= (last * (last + 1)) / 2;
        int i = 0;
        int term = (cnt * k) + 1;
        while (n) {
            if (term <= n) {
                ans[i++] = term;
                n -= term;
                term++;
            }
            else {
                ans[i] += n;
                n = 0;
            }
        }
        for (int i = 0; i < k; i++)
            ans[i] += (cnt * (i + 1))
                   + (k * (cnt * (cnt - 1)) / 2);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends