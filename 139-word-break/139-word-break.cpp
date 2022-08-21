class Solution {
private:
    int solve(string& s,unordered_set<string>&st,vector<int>&dp,int index){
        if(index>=s.size()){
            return 1;
        }
        
        if(dp[index]!=-1) return dp[index];
        
        for(int i = index+1;i<=s.size();i++){
            if(st.count(s.substr(index,i-index))!=0 && solve(s,st,dp,i)){
                return dp[index]=1;
            }
        }
        
        return dp[index]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        
        for(auto word: wordDict){
            st.insert(word);
        }
        
        vector<int>dp(s.size(),-1);
        
        return solve(s,st,dp,0);
    }
};