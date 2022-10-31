class Solution {
    int solve(string& ring,string& key,int ringidx,int keyidx,vector<vector<int>>&dp){
        if(keyidx>=key.length()) return 0;
        
        
        if(dp[ringidx][keyidx]!=-1) return dp[ringidx][keyidx];
        int i=0;
        int cnt=0;
        int mini = INT_MAX;
        while(cnt!=ring.length()){
            i=i%ring.length();
            if(ring[i]==key[keyidx]){
                mini = min(mini,(min((int)(ring.length()-abs(i-ringidx)),abs(i-ringidx)) + solve(ring,key,i,keyidx+1,dp))); 
            }
            i++;
            cnt++;
        }
        
        return dp[ringidx][keyidx]=mini;
    }
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.length()+1,vector<int>(key.length()+1,-1));
        return solve(ring,key,0,0,dp)+key.length();
    }
};