class Solution {
    int solve(vector<int>& nums,int idx,int sum,int target){
        if(idx==nums.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int choice1 = solve(nums,idx+1,sum+nums[idx],target);
        int choice2 = solve(nums,idx+1,sum-nums[idx],target);
        
        return choice1 + choice2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,0,target);
    }
};