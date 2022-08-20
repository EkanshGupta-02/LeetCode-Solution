class Solution {
    int solve(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        
        if(dp[index]!=-1) return dp[index];
        
        int incl = nums[index] + solve(nums,index+2,dp);
        int excl = solve(nums,index+1,dp);
        
        return dp[index] = max(incl,excl);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>nums1(nums.begin()+1,nums.end());
        vector<int>nums2(nums.begin(),nums.end()-1);
        
        vector<int>dp(nums1.size(),-1);
        vector<int>dp1(nums2.size(),-1);
        
        return max(solve(nums1,0,dp),solve(nums2,0,dp1));
    }
};