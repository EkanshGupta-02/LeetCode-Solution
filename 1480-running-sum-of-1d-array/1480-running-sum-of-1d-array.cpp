class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        ans[0]=nums[0];
       long long sum=nums[0];
        
        for(int i=1;i<n;i++){
            sum+=nums[i];
            ans[i]=sum;
        }
        
        return ans;
    }
};
 