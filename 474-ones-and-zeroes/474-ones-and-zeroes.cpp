class Solution {
private:
    int solve(vector<string>&str,int m,int n,int index,vector<vector<vector<int>>>&dp){
        if(m<0 || n<0 || index>=str.size()){
            return 0;
        }
        
        if(dp[m][n][index]!=-1)return dp[m][n][index];
        int on=0;
        int ze=0;
        
        string st = str[index];
        for(auto s:st){
            if(s=='0')ze++;
            else on++;
        }
        
        if(on>n || ze>m){
            return dp[m][n][index] = solve(str,m,n,index+1,dp);
        }
        else{
            return dp[m][n][index] = max(1 + solve(str,m-ze,n-on,index+1,dp),solve(str,m,n,index+1,dp)); 
        }   
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size()+1,-1)));
        return solve(strs,m,n,0,dp);
    }
};