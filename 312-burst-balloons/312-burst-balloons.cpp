class Solution {
private:
    int solve(vector<int>&nums,int s,int e,vector<vector<int>>&dp){
        if(s>e){
            return 0;
        }
        
        if(dp[s][e]!=-1) return dp[s][e];
        int ans=INT_MIN;
        
        for(int i=s;i<=e;i++){
            int val = nums[s-1]*nums[i]*nums[e+1]+solve(nums,s,i-1,dp)+solve(nums,i+1,e,dp);
            ans = max(ans,val);
        }
        
        return dp[s][e] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,1,n,dp);
    }
};