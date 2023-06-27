//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
int solve(int n,int arr[],int index,int prev,vector<vector<int>>&dp){
    if(index>=n ){
            return 0;
    }
    
    if(dp[index][prev+1]!=-1) return dp[index][prev+1];
    int include = 0;
    if(prev==-1 || abs(arr[index]-arr[prev])==1){
        include = 1+solve(n,arr,index+1,index,dp);
    }
    
    int exclude  = solve(n,arr,index+1,prev,dp);
    
    return dp[index][prev+1] = max(include,exclude);
}

int solvetab(int N,int arr[]){
    vector<vector<int>>dp(N+1,vector<int>(N+1,0));
    
    for(int i=N-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            int include = 0;
                if(j==-1 || abs(arr[i]-arr[j])==1){
                    include = 1+dp[i+1][i];
                }
                
                int exclude  = dp[i+1][j+1];
                
               dp[i][j+1] = max(include,exclude);
        }
    }
    
    return dp[0][0];
}

public:
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return solve(N,A,0,-1,dp);
        
        // return solvetab(N,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends