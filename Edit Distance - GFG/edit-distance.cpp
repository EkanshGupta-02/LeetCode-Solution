//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int i, int j, string s, string t, vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j]=f(i-1, j-1, s, t, dp);
        }else{
            int ins=1+f(i, j-1, s, t, dp);
            int del=1+f(i-1, j, s, t, dp);
            int sub=1+f(i-1, j-1, s, t, dp);
            return dp[i][j]=min(ins, min(del, sub));
        }
    }
  
    int editDistance(string s, string t) {
        // Code here
        
        int x=s.size();
        int y=t.size();
        vector<vector<int>>dp(x, vector<int>(y, -1));
        return f(x-1, y-1, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends