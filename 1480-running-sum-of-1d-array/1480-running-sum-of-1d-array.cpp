class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        
        int i=0;
        int n=nums.size();
        vector<int> ans(n);
        
        while(i<n){
            int runsum=nums[i];
            ans[i]=runsum;
            
            if(i>0){
                int temp=ans[i-1];
                ans[i]+=temp;
            }
            
            i++;
        }
        
        return ans;
    }
};
 