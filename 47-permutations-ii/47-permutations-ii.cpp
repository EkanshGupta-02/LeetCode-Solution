class Solution {
public:
    set<vector<int>> ans;
    
    void solve(vector<int>& nums,int idx){
        
        if(idx==nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
             swap(nums[idx],nums[i]);
            
             solve(nums,idx+1);
            
             swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        solve(nums,0);
        
        return {ans.begin(),ans.end()};
        
    }
};