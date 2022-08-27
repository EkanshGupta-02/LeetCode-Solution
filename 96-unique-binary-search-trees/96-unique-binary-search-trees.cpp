class Solution {
private:
    int solve(int n){
        if(n<=1){
            return 1;
        }
        
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            ans += solve(i-1)*solve(n-i);
        }
        
        return ans;
    }
    
    int solvemem(int n,vector<int>&dp){
         if(n<=1){
            return 1;
        }
        
        if(dp[n] != -1) return dp[n];
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            ans += solvemem(i-1,dp)*solvemem(n-i,dp);
        }
        
        return dp[n] = ans;
    }
    
    int solvetab(int x){
        vector<int>dp(x+1,0);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int n=2;n<=x;n++){
        
            int ans=0;
        
            for(int i=1;i<=n;i++){
                ans += dp[i-1]*dp[n-i];
            }
            
            dp[n]=ans;
        }
        
        return dp[x];
    }
    
public:
    int numTrees(int n) {
        // vector<int>dp(n+1,-1);
        return solvetab(n);
    }
};