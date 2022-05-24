class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int t=n;
        
        if(n==1){
            return nums[0]==1?0:1;
        }
        
        for(int i=0;i<n;i++){
            if(nums[n-i-1]!=t){
                return t;
            }
            t--;
        }
        
        return t;
    }
};