class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int low=0;
       int same=0;
        int high;
        
        for(auto n:nums){
            if(n<pivot){
                low++;
            }
            else if(n==pivot){
                same++;
            }
        }
        
        high = low+same;
        same = low;
        low=0;
        
        vector<int>ans(nums.size());
        for(auto n:nums){
            if(n<pivot){
                ans[low++]=n;
            }
            else if(n==pivot){
                ans[same++]=n;
            }
            else{
                ans[high++]=n;
            }
        }
        
        return ans;
    }
};