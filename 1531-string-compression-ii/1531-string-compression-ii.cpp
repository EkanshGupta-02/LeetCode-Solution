class Solution {
    int solve(int idx,string& s,int k,int freqcnt,char prev,int dp[][27][11][101]){
        if(k<0){
            return 1e9;
        }
        
        if(idx>=s.size()){
            return 0;
        }
        
        if(freqcnt >= 10)
            freqcnt = 10;
        
        if(dp[idx][prev - 'a'][freqcnt][k] != -1)
            return dp[idx][prev - 'a'][freqcnt][k];
        
        int res = 1e9;
        
     // case1:
        res = min(res,solve(idx+1,s,k-1,freqcnt,prev,dp));
        
    // case2:
        if(s[idx] != prev){
            res = min(res, 1 + solve(idx+1,s,k,1,s[idx],dp) );
        }
        
    else{
            
            // case 3.1
            if(freqcnt == 1 || freqcnt == 9 || freqcnt == 99)
            {
                res = min(res, 1 + solve(idx+1,s,k,freqcnt + 1,prev,dp));
            }
            
            // case 3.2
            else{
                res = min(res, solve(idx+1,s,k,freqcnt+1,prev,dp));
            }
        }
        
        return dp[idx][prev - 'a'][freqcnt][k] = res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        
        if(n == 100)
        {
            bool allSame = true;
            
            // Base case: check for all char are same
            for(int i = 1; i < n; i++)
            {
                if(s[i] != s[i-1])
                {
                    allSame = false;
                    break;
                }
            }

            if(allSame) return 4;
        }
        
        
        int dp[n+1][27][11][101];
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, s , k , 0 ,'z' + 1,dp);
    }
};