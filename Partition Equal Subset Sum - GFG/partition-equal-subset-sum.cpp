//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int idx,int arr[],int n,int target,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int incl = solve(idx+1,arr,n,target-arr[idx],dp);
        int excl = solve(idx+1,arr,n,target,dp);
        
        return dp[idx][target] = incl or excl;
    }
    int equalPartition(int N, int arr[])
    {
        int tot = accumulate(arr,arr+N,0);
        vector<vector<int>>dp(N,vector<int>(tot/2 +1,-1));
        if(tot&1) return 0;
        return solve(0,arr,N,tot/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends