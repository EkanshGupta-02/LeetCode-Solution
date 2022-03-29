class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int p=0;
        int q=n-1;
        
        while(p<=q){
            int m=p+(q-p)/2;
            
            if(nums[m]==target){
                return m;
            }
            
            if(nums[p]<=nums[m]){
                if(target>=nums[p] && target<=nums[m]){
                    q=m-1;
                }
                else{
                    p=m+1;
                }
            }
            
            else{
                if(target>=nums[m] && target<=nums[q]){
                    p=m+1;
                }
                else{
                    q=m-1;
                }
            }
        }
        
        return -1;
    }
};