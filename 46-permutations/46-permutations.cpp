class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>& nums,int idx){
            
        if(idx==nums.size()){
            ans.push_back(nums);
        }
        
        for(int j=idx;j<nums.size();j++){
            swap(nums[idx],nums[j]);
            
            solve(nums,idx+1);
            
            swap(nums[idx],nums[j]);
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       
        solve(nums,0);
        
        return ans;
    }
};