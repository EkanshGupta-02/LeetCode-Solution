class Solution {
private:
    int solve(string& word1,string& word2,int i,int j,vector<vector<int>>&dp){
        if(i == word1.length()){
            return word2.length()-j;
        }
        
        if(j == word2.length()){
            return word1.length()-i;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(word1[i]==word2[j]){
            ans = solve(word1,word2,i+1,j+1,dp);
        }
        else{
        
        int insert = solve(word1,word2,i,j+1,dp);
        int replace = solve(word1,word2,i+1,j+1,dp);
        int deleteans = solve(word1,word2,i+1,j,dp);
        
        ans = 1 + min(insert,min(replace,deleteans));
    }
        
        return dp[i][j] = ans;
    }
    
    int solvetab(string& a,string& b){
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        
         for(int j=0;j<b.length();j++){
            dp[a.length()][j] = b.length()-j;
        }
        
        for(int i=0;i<a.length();i++){
            dp[i][b.length()]=a.length()-i;
        }
        
       
        
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                
                if(a[i]==b[j]){
                     ans = dp[i+1][j+1];
                }
                    
               else {
                   int insert = dp[i][j+1];
                int replace =dp[i+1][j+1];
                int deleteans = dp[i+1][j];

                    ans = 1 + min(insert,min(replace,deleteans));  
               } 
                dp[i][j]=ans;
        }
    }
        return dp[0][0];
    }
    public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solvetab(word1,word2);
        
    }
};