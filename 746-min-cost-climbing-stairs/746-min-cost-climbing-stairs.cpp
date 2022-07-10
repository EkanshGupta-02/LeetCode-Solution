class Solution {
public:    
    
    int solve(vector<int>& cost,int n){
        vector<int>dp(n+1,-1);
        
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost,cost.size());
    }
};