class Solution {
public:
    
    int firocc(vector<int>nums,int target){
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        int m=(s+e)/2;
        
        while(s<=e){
            
            if(nums[m]==target){
                ans=m;
                e=m-1;
            }
            
           else if(nums[m]<target){
                s=m+1;
            }
            
            else{
                
                e= m-1;
            }
            
            m=s+(e-s)/2;
        }
        
        return ans;
    }
    
       int lasocc(vector<int>nums,int target){
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        int m=(s+e)/2;
        
        while(s<=e){
            
            if(nums[m]==target){
                ans=m;
                s=m+1;
            }
            
            else if(nums[m]<target){
                s=m+1;
            }
            
            else{
                
                e= m-1;
            }
            
            m=s+(e-s)/2;
        }
        
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back(firocc(nums,target));
        ans.push_back(lasocc(nums,target));
        
        return ans;
    }
};