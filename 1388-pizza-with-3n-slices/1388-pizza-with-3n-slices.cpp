class Solution {
private:
    int solve(int start,int end,vector<int>&slices,int avlblslice,vector<vector<int>>&dp){
        if(avlblslice==0 || start>end){
            return 0;
        }
        
        if(dp[start][avlblslice]!=-1) return dp[start][avlblslice];
        
        int take = slices[start] + solve(start+2,end,slices,avlblslice-1,dp);
        int nottake = solve(start+1,end,slices,avlblslice,dp);
        
        return dp[start][avlblslice] = max(take,nottake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        int case1 = solve(0,n-2,slices,n/3,dp1);
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        int case2 = solve(1,n-1,slices,n/3,dp2);
        
        return max(case1,case2);
    }
};