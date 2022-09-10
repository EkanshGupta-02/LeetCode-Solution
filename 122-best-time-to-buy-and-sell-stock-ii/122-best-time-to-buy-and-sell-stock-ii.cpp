class Solution {
private:
    int solve(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if (index==prices.size()){
            return 0;
        }
        
        if(dp[index][buy]!=-1) return dp[index][buy];
        
        int profit=0;
        
        if(buy){
            profit = max((-prices[index]+solve(index+1,0,prices,dp)),(solve(index+1,1,prices,dp)));
        }
        else{
            profit = max((prices[index]+solve(index+1,1,prices,dp)),(solve(index+1,0,prices,dp)));
        }
        
        return dp[index][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};