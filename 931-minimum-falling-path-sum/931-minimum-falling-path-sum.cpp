class Solution {
private:
    int solve(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp){
        if(col<0 || col>=matrix[0].size()){
            return 1e9;
        }
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        if(row==0){
            return dp[row][col] = matrix[row][col];
        }
        
        long long int up = matrix[row][col] + solve(matrix,row-1,col,dp);
        long long  int rd = matrix[row][col] + solve(matrix,row-1,col+1,dp);
         long long int ld = matrix[row][col] + solve(matrix,row-1,col-1,dp);
        
        return dp[row][col] = min({up,ld,rd});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        
        int ans  = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans,solve(matrix,n-1,i,dp));
        }
        return ans;
    }
};