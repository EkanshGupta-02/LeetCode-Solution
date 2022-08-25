class Solution {
int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
    int maximum=1;
    
    if(dp[row][col]!=-1) return dp[row][col];
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    
    for(int k=0;k<4;k++){
        int newrow = row + delrow[k];
        int newcol = col + delcol[k];
        
        if(newrow<0 || newrow>=matrix.size() || newcol<0 || newcol>=matrix[0].size() || matrix[newrow][newcol]<=matrix[row][col]) continue;
        
        maximum = max(maximum,1+solve(matrix,newrow,newcol,dp));
    }
    
    return dp[row][col] = maximum;
}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi,solve(matrix,i,j,dp));
            }
        }
        
        return maxi;
    }
};