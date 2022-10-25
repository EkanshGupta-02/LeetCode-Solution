class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
         int count=0;
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++)
        if(nums[i]==nums[i-1]){
            ++nums[i];
            ++count;  }
        else if(nums[i]<nums[i-1]){
            int k = nums[i-1]-nums[i];
            count+=k+1;
            nums[i]+=k+1;
        }
    return count;
    }
};