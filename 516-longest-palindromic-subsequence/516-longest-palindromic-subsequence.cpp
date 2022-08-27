class Solution {
private:
int solve(string& s,string& t,int i,int j,vector<vector<int>>&dp){
    if(i==s.length() || j==t.length()){
        return 0;
    }
    int ans=0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s[i]==t[j]){
        ans = 1 + solve(s,t,i+1,j+1,dp);
    }
    else{
        int op1 = solve(s,t,i+1,j,dp);
        int op2 = solve(s,t,i,j+1,dp);
        
        ans = max(op1,op2);
    }
    
    return dp[i][j] = ans;
}
    
int solvetab(string& a,string& b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
        int ans=0;
    if(a[i]==b[j]){
        ans = 1 + dp[i+1][j+1];
    }
    else{
        int op1 = dp[i+1][j];
        int op2 = dp[i][j+1];
        
        ans = max(op1,op2);
    }
            dp[i][j]=ans;
        }
    }
    
    return dp[0][0];
}
    public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        // vector<vector<int>>dp(s.length()+1,vector<int>(rev.length()+1,-1));
        return solvetab(s,rev);
    }
};