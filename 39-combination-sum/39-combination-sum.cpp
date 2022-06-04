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
        
      
        
        for(int index=i;index<candidates.size();index++){
            
            
                temp.push_back(candidates[index]);
        
                solve(candidates,target-candidates[index],ans,temp,index);
        
                temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(candidates,target,ans,temp,0);
        
        return ans;
    }
};