class Solution {
public:
    void solve(int k,int n,vector<vector<int>>& ans,vector<int>& temp,int num){
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }
        
        if(n<0){
            return ;
        }
        
        for(int i=num;i<=9;i++){
            temp.push_back(i);
            solve(k-1,n-i,ans,temp,i+1);
            
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(k,n,ans,temp,1);
        
        return ans;
    }
};