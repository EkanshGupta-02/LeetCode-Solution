class Solution {
    int solve(vector<int>& nums,int idx,int sum,int target,vector<vector<int>>&dp,int& total){
        if(idx==nums.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[idx][sum+total]!=-1) return dp[idx][sum+total];
        
        int choice1 = solve(nums,idx+1,sum+nums[idx],target,dp,total);
        int choice2 = solve(nums,idx+1,sum-nums[idx],target,dp,total);
        
        return dp[idx][sum+total] = choice1 + choice2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*total+1,-1));
        return solve(nums,0,0,target,dp,total);
    }
};