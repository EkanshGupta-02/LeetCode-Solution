class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int crstreak=1;
        int lngstreak=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    crstreak+=1;
                }
                else{
                lngstreak=max(lngstreak,crstreak);
                crstreak=1;
            }
        }
            
    }   
        return max(lngstreak,crstreak);
    }
};