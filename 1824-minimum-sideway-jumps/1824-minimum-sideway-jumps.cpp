class Solution {
private:
    int solve(vector<int>&obs,int curlane,int curpos,vector<vector<int>>&dp){
        int laspos = obs.size()-1;
        if(curpos == laspos){
            return 0;
        }
        
        if(dp[curlane][curpos]!=-1) return dp[curlane][curpos];
        
        if(obs[curpos+1]!=curlane){
            return solve(obs,curlane,curpos+1,dp);
        }
        else{
            int ans =INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=curlane && obs[curpos]!=i){
                    ans = min(ans, 1 + solve(obs,i,curpos,dp));
                }
            }
            return dp[curlane][curpos] = ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int currlane = 2;
        int currpos = 0;
        vector<vector<int>>dp(4,vector<int>(obstacles.size()+1,-1));
        return solve(obstacles,currlane,currpos,dp);
    }
};