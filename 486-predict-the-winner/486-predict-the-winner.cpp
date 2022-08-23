class Solution {
public:
    int solve(vector<int>arr,int i,int j,vector<vector<int>>&dp){
        if(i>j){
        return 0;
    }
        if(dp[i][j]!=-1) return dp[i][j];

    int choice1 = arr[i]+min(solve(arr,i+1,j-1,dp),solve(arr,i+2,j,dp));
    int choice2 = arr[j]+min(solve(arr,i+1,j-1,dp),solve(arr,i,j-2,dp));

    int ans=max(choice1,choice2);
    
         return dp[i][j] = ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
       float totsum=0;
        int n = nums.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(auto n:nums){
            totsum+=n;
        }
        
        int ans = solve(nums,0,nums.size()-1,dp);
        
        return ans>=totsum/2.0;
    }
};