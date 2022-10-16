class Solution {
public:
    int solve(vector<int>&job,int d,int n,int idx,vector<vector<int>>&dp){
        if(d==1){
            return *max_element(begin(job)+idx,end(job));
        }
        
        if(dp[idx][d]!=-1) return dp[idx][d];
        int Max=INT_MIN;
        int result = INT_MAX;
        
        for(int i=idx;i<=n-d;i++){
             Max = max(Max, job[i]);
            result = min(result, Max + solve(job,d-1,n,i+1,dp));
        }
        
        return dp[idx][d] = result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(jobDifficulty.size()<d){
            return -1;
        }
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(jobDifficulty,d,n,0,dp);
    }
};