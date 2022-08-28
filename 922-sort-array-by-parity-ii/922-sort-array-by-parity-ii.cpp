class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if((i%2==0 && nums[i]%2==0) || (i%2!=0 && nums[i]%2!=0)){
                continue;
            }        
            if(i%2==0 && nums[i]%2!=0){
                int j = i+1;
                while(j<n && nums[j]%2!=0){
                    j++;
                }
                if(j<n){
                    swap(nums[i],nums[j]);
                }
            }
            else{
                int j = i+1;
                while(j<n && nums[j]%2==0){
                    j++;
                }
                if(j<n){
                    swap(nums[i],nums[j]);
                }
            }
        }
    
        return nums;
    }
};