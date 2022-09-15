class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi=0;
        int currlen = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                currlen++;
            }
            else{
                maxi = max(currlen+1,maxi);
                currlen=0;
            }
        }
        maxi = max(currlen+1,maxi);
        
        return maxi;
    }
};