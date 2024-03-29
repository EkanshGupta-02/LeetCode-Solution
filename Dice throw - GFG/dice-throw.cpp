//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int dice,int m,int target){
        if(target<0) return 0;
        if(dice==0 && target!=0) return 0;
        if(dice!=0 && target==0) return 0;
        if(dice ==0 && target==0) return 1;
        
        long long ans = 0;
        for(int i=1;i<=m;i++){
            ans = ans + solve(dice-1,m,target-i);
        }
        
        return ans;
    }
     long long solvemem(int dice,int m,int target,vector<vector<long long>>&dp){
        if(target<0) return 0;
        if(dice==0 && target!=0) return 0;
        if(dice!=0 && target==0) return 0;
        if(dice ==0 && target==0) return 1;
        
        if(dp[dice][target]!=-1) return dp[dice][target];
        
        long long ans = 0;
        for(int i=1;i<=m;i++){
            ans = ans + solvemem(dice-1,m,target-i,dp);
        }
        
        return dp[dice][target]  = ans;
    }
    
    long long solvetab(int d,int m,int t){
        vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
        dp[0][0] = 1;
        
        for(int dice = 1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                long long ans = 0;
                for(int i=1;i<=m;i++){
                    if(target-i>=0)
                        ans = ans + dp[dice-1][target-i];
                }
                dp[dice][target]  = ans;
            }
        }
        
        return dp[d][t];
    }
    long long noOfWays(int M , int N , int X) {
    //   vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        return solvetab(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends