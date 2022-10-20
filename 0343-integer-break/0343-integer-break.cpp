class Solution {
    int solve(int num,int sum,vector<vector<int>>&dp){
        if(num==1){
            return 1;
        }
        if(num<0){
            return 0;
        }
        if(dp[num][sum]!=-1){
            return dp[num][sum];
        }
        int nottaken = solve(num-1,sum,dp);
        
        int taken = 0;
        if(sum>=num){ 
            taken = num*solve(num,sum-num,dp);
        }
        
        return dp[num][sum] = max(taken,nottaken);
    }
public:
    int integerBreak(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n-1,n,dp);      
    }
};