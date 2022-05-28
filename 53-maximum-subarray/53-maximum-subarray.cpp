class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maximum=nums[0];
        int tempmax=nums[0];
        
        for(int i=1;i<nums.size();i++){
            tempmax=max(tempmax+nums[i],nums[i]);
            maximum=max(maximum,tempmax);
        }
        
        return maximum;
    }
};