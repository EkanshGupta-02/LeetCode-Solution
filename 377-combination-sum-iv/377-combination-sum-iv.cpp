class Solution {
public:
    int solve(vector<int>&nums,int target,vector<int>&dp,int currsum){
        if(target==currsum) return 1;
        if(currsum>target) return 0;
        
        if(dp[currsum]!=-1)return dp[currsum];
        int ways = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(currsum+nums[i]<=target){
                ways+=solve(nums,target,dp,currsum+nums[i]);
            }
        }
        
        return dp[currsum]=ways;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
     
        vector<int>dp(target+1,-1);
        return solve(nums,target,dp,0);
    }
};