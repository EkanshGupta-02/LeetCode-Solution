class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int mxi=INT_MIN;
        int index=1;
        
        for(int i=0;i<n;i++){
            if(mxi<nums[i]){
                index=i;
                mxi=nums[i];
            }
        }
        
        for(int i=0;i<n;i++){
            if(mxi!=nums[i]){
                if(mxi>=2*nums[i]){
                    continue;
                }
                else {
                    return -1;
                }
            }
        }
        
        return index;
    }
};