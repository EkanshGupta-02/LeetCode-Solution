class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;int j=0;
        
        while(j<nums.size()){
            if(nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        
        return nums;
    }
};