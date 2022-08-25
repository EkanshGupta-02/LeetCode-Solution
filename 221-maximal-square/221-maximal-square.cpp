class Solution {
    int solve(vector<vector<char>>&matrix,int i,int j,int& maxi,vector<vector<int>>&dp){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(matrix,i,j+1,maxi,dp);
        int bottom = solve(matrix,i+1,j,maxi,dp);
        int diagonal = solve(matrix,i+1,j+1,maxi,dp);
        
        int ans=0;
        if(matrix[i][j]=='1'){
            ans = 1 + min(right,min(bottom,diagonal));
            maxi = max(maxi,ans);
        }
        return dp[i][j] = ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        solve(matrix,0,0,maxi,dp);
        
        return maxi*maxi;
    }
};