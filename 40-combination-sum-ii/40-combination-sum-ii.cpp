class Solution {
private:
    void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>temp,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(target<0 || index>=candidates.size()){
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i != index && candidates[i]==candidates[i-1]){
                continue;
            }
            
            if(candidates[i]>target) break;
            
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,temp,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(candidates,target,ans,temp,0);
        
        return ans;
    }
};