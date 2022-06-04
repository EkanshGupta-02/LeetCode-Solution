class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&temp,int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        
        //  exclude
        solve(candidates,target,ans,temp,i+1);
        
        // include
        temp.push_back(candidates[i]);
        
        solve(candidates,target-candidates[i],ans,temp,i);
        
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(candidates,target,ans,temp,0);
        
        return ans;
    }
};