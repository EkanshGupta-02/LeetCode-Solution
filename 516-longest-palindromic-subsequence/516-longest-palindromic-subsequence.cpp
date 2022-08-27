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
    public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(s.length()+1,vector<int>(rev.length()+1,-1));
        return solve(s,rev,0,0,dp);
    }
};