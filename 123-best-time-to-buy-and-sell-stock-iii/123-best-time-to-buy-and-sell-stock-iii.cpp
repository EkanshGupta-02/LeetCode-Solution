class Solution {
    int solve(int index,int buy,vector<int>&prices,int limit,vector<vector<vector<int>>>&dp){
        if (index==prices.size()){
            return 0;
        }
        
        if(limit==0){
            return 0;
        }
        
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
        
        int profit=0;
        
        if(buy){
            profit = max((-prices[index]+solve(index+1,0,prices,limit,dp)),(solve(index+1,1,prices,limit,dp)));
        }
        else{
            profit = max((prices[index]+solve(index+1,1,prices,limit-1,dp)),(solve(index+1,0,prices,limit,dp)));
        }
        
        return dp[index][buy][limit] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,prices,2,dp);
    }
};