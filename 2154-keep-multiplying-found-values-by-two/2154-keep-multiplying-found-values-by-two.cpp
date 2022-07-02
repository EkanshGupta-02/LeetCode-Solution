class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int i = 0;
        int n = nums.size();
       while(i < n) {
           if(nums[i] == original) {
                i = 0;
                original = original * 2;
            }
           else
                 i++;
             }
       return original;

    }
};