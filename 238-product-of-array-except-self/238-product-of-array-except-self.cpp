class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int n1=1,n2=1;
        
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=n1;
            n1=n1*nums[i];
            
            int j=n-i-1;
            
            ans[j]*=n2;
            n2*=nums[j];
        }
        
        return ans;
    }
};