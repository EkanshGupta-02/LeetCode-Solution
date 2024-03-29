//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int solve(string a,string b,string c, int n1, int n2, int n3,int i,int j,int k,vector<vector<vector<int>>>& dp){
    if(i==n1 || j==n2 || k==n3){
        return 0;
    }
    
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    
    if(a[i]==b[j] and b[j]==c[k]){
        return dp[i][j][k] = 1+solve(a,b,c,n1,n2,n3,i+1,j+1,k+1,dp);
    }else{
        int s1 = solve(a,b,c,n1,n2,n3,i+1,j,k,dp);
        int s2 = solve(a,b,c,n1,n2,n3,i,j+1,k,dp);
        int s3 = solve(a,b,c,n1,n2,n3,i,j,k+1,dp);
        
        return dp[i][j][k] = max(s1,max(s2,s3));
    }
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
    return solve(A,B,C,n1,n2,n3,0,0,0,dp);
}