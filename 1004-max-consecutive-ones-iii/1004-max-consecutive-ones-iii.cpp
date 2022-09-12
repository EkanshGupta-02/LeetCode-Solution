class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        int temp=0;
        
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            temp++;
            
            while(temp-sum>k){
                sum -= nums[i-temp+ 1];
                temp--;
            }
            
            ans=max(ans,temp);
        }
        
        return ans;
    }
};