class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        
        int t=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            t=min(t,nums[i]);
        }
        
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-t);
        }
        
        return ans;
    }
};