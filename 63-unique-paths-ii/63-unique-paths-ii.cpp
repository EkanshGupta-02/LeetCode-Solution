class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>&grid,int&m,int&n,int i,int j){
        if(i==m || j==n || grid[i][j]) return 0;
        if(i==m-1 && j==n-1) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = solve(dp,grid,m,n,i+1,j) + solve(dp,grid,m,n,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        int ans = solve(dp,obstacleGrid,m,n,0,0);
        
        return ans;
    }
};