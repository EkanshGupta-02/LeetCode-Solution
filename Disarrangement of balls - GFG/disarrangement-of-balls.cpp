//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int MOD = 1e9+7;
    long int solve(int n, vector<long int>&dp){
        if(n==1) return 0;
        if(n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        dp[n] = (((n-1)%MOD)*((solve(n-1,dp))%MOD + (solve(n-2,dp))%MOD))%MOD;
        return dp[n];
    }
    long int disarrange(int n){
        vector<long int>dp(n+1,-1);
        long int ans = solve(n,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends