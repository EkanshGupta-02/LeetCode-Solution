class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return -1;
       int maxi=nums[0];
       int mini=nums[0];
       int ans = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int t1 = maxi*nums[i];
            int t2 = mini*nums[i];
            maxi = max(nums[i],max(t1,t2));
            mini = min(nums[i],min(t1,t2));
            
            ans = max(ans,maxi);
        }
        
        return ans;
    }
};