class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>maxi(nums.size());
        vector<int>mini(nums.size());
        
        maxi[0]=nums[0];
        mini[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                maxi[i] = max(nums[i],nums[i]*mini[i-1]);
                mini[i] = min(nums[i],nums[i]*maxi[i-1]);
            }
            else{
                maxi[i] = max(nums[i],nums[i]*maxi[i-1]);
                mini[i] = min(nums[i],nums[i]*mini[i-1]);
            }
        }
        
        return *max_element(maxi.begin(),maxi.end());
    }
};