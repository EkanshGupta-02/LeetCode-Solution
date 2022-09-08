class Solution {
private:
    void solve(vector<int>&nums,set<vector<int>>&res,vector<int>&temp,int ind,int prev){
        if(ind==nums.size()){
            if(temp.size()>=2){
            res.insert(temp);
           }
            return;
        }
        if(nums[ind]>=prev){
            temp.push_back(nums[ind]);
            solve(nums,res,temp,ind+1,nums[ind]);
            temp.pop_back();
        }
      solve(nums,res,temp,ind+1,prev);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>res;
        
        solve(nums,res,temp,0,INT_MIN);
        
        vector<vector<int>>ans(res.begin(),res.end());
        
        return ans;
    }
};