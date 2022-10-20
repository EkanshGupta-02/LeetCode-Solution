class Solution {
    int solve(vector<vector<int>>&mat,int row,int col,vector<vector<int>>&dp){
        if(row>=mat.size() || col>=mat[0].size()){
            return INT_MAX;
        }
        
        if(row == mat.size()-1 && col==mat[0].size()-1){
            return mat[row][col]>0 ? 1 : 1 - mat[row][col];
        }
        
        if(dp[row][col]!=-1) return dp[row][col];
        int right = solve(mat,row,col+1,dp);
        int down = solve(mat,row+1,col,dp);
        
        int ans = min(right,down) - mat[row][col];
        
        return dp[row][col] = ans>0? ans : 1;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       int n = dungeon.size();
        int m = dungeon[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return  solve(dungeon,0,0,dp);
    }
};