class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        
        int ans=0;
         
        int lm=0,rm=0;
        
        while(l<r){
            if(height[l]<height[r]){
            height[l]>lm?(lm=height[l]):(ans+=lm-height[l]);
             l++;
            }
            
            else{
                
                height[r]>rm?(rm=height[r]):(ans+=rm-height[r]);
                
                r--;
                
            }
            
            
        }
        
        return ans;
    }
};