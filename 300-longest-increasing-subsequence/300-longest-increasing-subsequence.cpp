class Solution {
public:
    int lis(int ind,int prev,vector<int>&nums){
        if(ind==nums.size()) return 0;
        
//         Not take
        int len=0+lis(ind+1,prev,nums);
        if(prev==-1 || nums[ind]>nums[prev]){
            len = max(len,1+lis(ind+1,ind,nums));
        }
        
        return len;
    }
    int lismem(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==nums.size()) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
//         Not take
        int len=0+lismem(ind+1,prev,nums,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            len = max(len,1+lismem(ind+1,ind,nums,dp));
        }
        dp[ind][prev+1]=len;
        
        return dp[ind][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return lismem(0,-1,nums,dp);
    }
};