class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        
        if(nums.size()==1){
            return 0;
        }
        
        while(s<=e){
            
            int m =(s+e)/2;  
            if(s==e){
                return s;
            }
            
            if(nums[m]>nums[m+1]){
                e=m;
            }
            else{
                s=m+1;
            }
        }
        
        return s;
    }
};