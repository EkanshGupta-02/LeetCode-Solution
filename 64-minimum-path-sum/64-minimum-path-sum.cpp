class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int m = INT_MAX;
        if(i>0){
        int top = grid[i][j]+solve(grid,i-1,j,dp);
        m = top;
        }
        
        if(j>0){
        int left = grid[i][j]+solve(grid,i,j-1,dp);
        m = min(m,left);
        }
        
        return dp[i][j]=m;
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};