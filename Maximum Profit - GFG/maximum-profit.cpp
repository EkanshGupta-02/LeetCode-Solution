//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int func(int ind,int buy,int A[],vector<vector<vector<int>>> &dp,int n,int l){
        if(l==0){
            return 0;
        }
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy][l]!=-1) return dp[ind][buy][l];
        if(buy){
            return dp[ind][buy][l]= max(-A[ind]+func(ind+1,0,A,dp,n,l),
             func(ind+1,1,A,dp,n,l));
        }
        else{
            return dp[ind][buy][l] = max(A[ind]+func(ind+1,1,A,dp,n,l-1),func(ind+1,0,A,dp,n,l));
        }
    }
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        int l=K;
        return func(0,1,A,dp,N,l);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends