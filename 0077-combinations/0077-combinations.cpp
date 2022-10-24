class Solution {
    void solve( vector<vector<int>>&ans,vector<int>&temp,int& n,int k,int num){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=num;i<=n;i++){
            temp.push_back(i);
            solve(ans,temp,n,k-1,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,n,k,1);
        return ans;
    }
};