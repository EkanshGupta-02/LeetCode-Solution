class Solution {
    int solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        if(amount<0 || index>=coins.size()) return 0;
        
        if(amount == 0) {
            return 1;
        }
        
        if(dp[index][amount]!=-1) return dp[index][amount];
        
//         incl
        int incl = solve(coins,amount-coins[index],index,dp);
        
        // excl
        int excl = solve(coins,amount,index+1,dp);
        
        return dp[index][amount] = incl+excl;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins,amount,0,dp);
        
        return ans;
    }
};