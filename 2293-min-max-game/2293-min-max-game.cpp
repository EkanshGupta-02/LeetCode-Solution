class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>ans(n/2,0);
        
        for(int i=0;i<n/2;i++){
            if(i&1){
                ans[i]=max(nums[2*i],nums[2*i+1]);
            }
            else{
                ans[i]=min(nums[2*i],nums[2*i+1]);
            }
        }
        
        if(ans.size()>1){
           return minMaxGame(ans);
        }
       return ans[0];
    }
};