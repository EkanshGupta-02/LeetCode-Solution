class Solution {
private:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
    
    int solveDPBS(vector<vector<int>>&a){
          int n = a.size();
            if(n==0){
                return 0;
            }
            
            vector<int>ans;
            ans.push_back(a[0][1]);
            
            for(int i=1;i<n;i++){
                if(a[i][1]>ans.back()){
                    ans.push_back(a[i][1]);
                }
                else{
                    int idx = lower_bound(ans.begin(),ans.end(),a[i][1])-ans.begin();
                    ans[idx]=a[i][1];
                }
            }
            
        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        return solveDPBS(envelopes);
    }
};