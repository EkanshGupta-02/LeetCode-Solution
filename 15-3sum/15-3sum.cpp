class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>temp;
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=n-1;
            
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    temp.insert({nums[i],nums[l],nums[r]});
                    r--;
                while(l<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                if(sum>0){
                    r--;
                }
                else{
                    l++;
                }
            }
            
        }
        
        vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;
    }
};