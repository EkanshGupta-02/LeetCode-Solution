class Solution {
public:
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i == s.length() && j == p.length())
            return true;
        else if(j == p.length())
            return false;
        else if(i == s.length()){
            return p[j] == '*' ? helper(s,p,i,j+1,dp) : false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j] == '*'){
            return dp[i][j] = helper(s,p,i,j+1,dp) || helper(s,p,i+1,j+1,dp) || helper(s,p,i+1,j,dp);
        }
        else if(p[j] == '?' || s[i] == p[j])
            return dp[i][j] = helper(s,p,i+1,j+1,dp);

        return dp[i][j] = false;        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
         return  helper(s,p,0,0,dp);
    }
};