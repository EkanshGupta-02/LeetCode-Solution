class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>& nums,int idx){
        
        int n=nums.size();
        
        if(idx==nums.size()-1){
            ans.push_back(nums);
            
            return ;
        }
        
        for(int i=idx;i<n;i++){
            
            swap(nums[idx],nums[i]);
            
            solve(nums,idx+1);
            
            swap(nums[idx],nums[i]);
        
        }
        
        return ;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       
        solve(nums,0);
        
        return ans;
    }
};