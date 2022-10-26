class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        
        int i=0;
        int j=0;
        int ans=0;
        
        long long mul=1;
        while(j<nums.size()){
            mul *= nums[j];
            
            while(mul>=k){
                mul/=nums[i];
                i++;
            }
            
            ans+=j-i+1;
            
            j++;
        }
        
        return ans;
    }
};