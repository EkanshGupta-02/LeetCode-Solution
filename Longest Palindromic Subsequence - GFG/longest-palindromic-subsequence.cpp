//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
 int solve(string &a,string&b,int i,int j,vector<vector<int>>&dp){
    if(i==a.length() || j==b.length()){
        return 0;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = 0;
    if(a[i] == b[j]){
        ans = 1 + solve(a,b,i+1,j+1,dp);
    }
    else{
        int opt1 = solve(a,b,i+1,j,dp);
        int opt2 = solve(a,b,i,j+1,dp);
        
        ans  = max(opt1,opt2);
    }
    
    return dp[i][j] = ans;
}
  public:
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(),B.end());
        vector<vector<int>>dp(A.length()+1,vector<int>(A.length()+1,-1));
        return solve(A,B,0,0,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends