class Solution {
private:
    int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            return piles[i];
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(piles[i]+solve(piles,i+1,j,dp),piles[j]+solve(piles,i,j-1,dp));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int first_score = solve(piles,0,n-1,dp);
        int second_score = sum - first_score;
        
        return first_score>second_score?true:false;
    }
};