class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int  sum=0;
        
        for(int i:nums){
            sum+=i;
        }
        
        sum=sum-x;
        
        if(sum==0){
            return nums.size();
        }
        
        if(sum<0){
            return -1;
        }
        
        int start=0,end=0;
        
        int ans=-1;
        
        int curr=nums[0];
        while(end<nums.size()){
               if(curr<sum){
                   end++;
                   if(end==nums.size()) break;
                   curr+=nums[end];
               }
            else if(curr>sum){
                curr-=nums[start];
                start++;
            }
            else{
                int val=end-start+1;
                ans=max(ans,val);
                curr-=nums[start];
                start++;
            }
        }
        
        if(ans==-1){
            return -1;   
        }
        else{
            return nums.size()-ans;
        }
    }
};