//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i,int j,vector<vector<int>> &M,vector<vector<int>>&dp,int n,int m){
     if (i < 0 || i >= n) {
    return -1;
}
    if(j==m-1 ){
        return M[i][j];
    }
     if(dp[i][j]!=-1) return dp[i][j];
      int up=M[i][j]+func(i-1,j+1,M,dp,n,m);
      int right=M[i][j]+func(i,j+1,M,dp,n,m);
      int down=M[i][j]+func(i+1,j+1,M,dp,n,m);
      
      return dp[i][j]= max(up,max(right,down));
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,func(i,0,M,dp,n,m));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends