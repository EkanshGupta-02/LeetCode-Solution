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
    
    int solvetab(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        
        for(int index = n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                         int profit=0;

                if(buy){
                    profit = max(-prices[index]+dp[index+1][0],(dp[index+1][1]));
                }
                else{
                    profit = max(prices[index]+dp[index+1][1],(dp[index+1][0]));
                }

                  dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return solve(0,1,prices,dp);
        return solvetab(prices);
    }
};