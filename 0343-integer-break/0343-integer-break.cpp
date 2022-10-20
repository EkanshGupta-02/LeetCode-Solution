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
    int solvetab(int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n+1;i++){
            dp[1][i]=1;
        }
        
        for(int num=2;num<n;num++){
            for(int sum = 0;sum<=n;sum++){
                int nottaken = dp[num-1][sum];
        
                int taken = 0;
                if(sum>=num){ 
                    taken = num*dp[num][sum-num];
                }
                dp[num][sum] = max(taken,nottaken);
            }
        }
        return dp[n-1][n];
    }
public:
    int integerBreak(int n) {
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(n-1,n,dp);      
        return solvetab(n);
    }
};