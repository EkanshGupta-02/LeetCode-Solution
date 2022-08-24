class Solution {
public:
    int f(vector<int> &nums,vector<int> &dp,int index){
//         Base condition
        if(index>= nums.size()-1) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        int ans = INT_MAX-100000;
        
        for(int j = 1;j<=nums[index];j++){
            ans = min (ans, 1 + f(nums,dp,index+j));
        }
        
        return  dp[index] = ans;
    }
    
    int jump(vector<int>& nums) {
        if(nums.size()==1 && nums[0]<1) return 0;
        int n = nums.size();
        vector<int> dp(n,-1);
//         calling recursive function to calculate.
        return f(nums,dp,0);
        
    }
};