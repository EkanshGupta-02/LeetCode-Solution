class Solution {
private:
    int mod=1e9+7;
public:
    int solve(int pre,int count,vector<vector<int>>&dp,int &n){
        if(count==n){
            return 1;
        }
        
        if(dp[count][pre]!=-1){
            return dp[count][pre];
        }
        
       long long int ans=0;
        
        for(int i=1;i<=5;i++){
            if(pre==1 && i==2){
                ans= ans%mod + solve(i,count+1,dp,n)%mod;
            }
            else if(pre==2 && (i==1 || i==3)){
                ans=ans%mod + solve(i,count+1,dp,n)%mod;
            }
            else if(pre==3 && i!=3){
                ans=ans%mod + solve(i,count+1,dp,n)%mod;
            }
            else if(pre==4 && (i==3 || i==5)){
                ans=ans%mod + solve(i,count+1,dp,n)%mod;
            }
            else if(pre==5 && i==1){
                ans=ans%mod + solve(i,count+1,dp,n)%mod;
            }
        }
        
        return dp[count][pre] = ans%mod;
    }
    
    int countVowelPermutation(int n) {
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        for(int i=1;i<=5;i++){
            ans = ans%mod +  solve(i,1,dp,n)%mod;
        }
        
        return ans%mod;
    }
};