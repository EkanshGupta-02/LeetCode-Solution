//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[],int N,int sum,int idx,vector<vector<long long int>>&dp){
        if(idx>=N || sum<0){
            return 0;
        }
        
        if(sum==0){
            return 1;
        }
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        // incl 
        long long int op1 = solve(coins,N,sum-coins[idx],idx,dp);
        
        //excl
        long long int op2 = solve(coins,N,sum,idx+1,dp);
        
        dp[idx][sum] = op1+op2;
       
        return op1 + op2; 
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+10000,-1));
        return solve(coins,N,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends