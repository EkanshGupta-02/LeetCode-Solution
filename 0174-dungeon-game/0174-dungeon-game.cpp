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
    int solvetab(vector<vector<int>>&mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        
        dp[n-1][m-1] = mat[n-1][m-1]>0 ? 1 : 1 - mat[n-1][m-1];
        
        for(int row = n-1;row>=0;row--){
            for(int col = m-1;col>=0;col--){
                if(row==n-1 && col==m-1){
                    continue;
                }
                int right = dp[row][col+1];
                int down = dp[row+1][col];

                int ans = min(right,down) - mat[row][col];

               dp[row][col] = ans>0? ans : 1;
            }
        }
        
        return dp[0][0];
    }
    
    int solvetabSO(vector<vector<int>>&mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<int>curr(m+1,0),next(m+1,INT_MAX-1000);
        
        curr[m] = 1e9;
        curr[m-1] = mat[n-1][m-1]>0 ? 1 : 1 - mat[n-1][m-1];
        
        for(int row = n-1;row>=0;row--){
            for(int col = m-1;col>=0;col--){
                if(row == n-1 && col == m-1){
                    continue;
                }
                int right = curr[col+1];
                int down = next[col];

                long long int ans = min(right,down) - mat[row][col];

               curr[col] = ans>0? ans : 1;
            }
           next = curr;
        }
        
        return curr[0];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       // int n = dungeon.size();
       //  int m = dungeon[0].size();
       // vector<vector<int>>dp(n,vector<int>(m,-1));
       // return  solve(dungeon,0,0,dp);
        return solvetabSO(dungeon);
    }
};