//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N, vector<vector<int>>&Matrix, int row, int col, vector<vector<int>>&dp)
 {
     if(dp[row][col]!=-1)
     {
         return dp[row][col];
     }
     if(row==N-1)
     {
         return Matrix[row][col];
     }
     
    int ans1=-1e9, ans2=-1e9, ans3=-1e9;
    if(row+1<N and col<N and col>=0)
    {
        ans1=Matrix[row][col]+solve(N,Matrix,row+1,col,dp);
    }
    if(row+1<N and col-1<N and col-1>=0)
    {
        ans2=Matrix[row][col]+solve(N,Matrix,row+1,col-1,dp);
    }
    if(row+1<N and col+1<N and col+1>=0)
    {
        ans3=Matrix[row][col]+solve(N,Matrix,row+1,col+1,dp);
    }
    return dp[row][col]= max(ans1,max(ans2,ans3));
    
    
 }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
      int ans=-1e9;
      int M= Matrix[0].size();
        vector<vector<int>>dp(N,vector<int>(M,-1));
        for(int i=0; i<Matrix[0].size(); i++)
        {
            int res=solve(N,Matrix,0,i,dp);
            ans=max(ans,res);
        }
        return  ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends