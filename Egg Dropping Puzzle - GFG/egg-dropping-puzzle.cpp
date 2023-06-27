//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     int dp[501][501];
     int helper(int eggs, int floors){
        if(floors == 0 or floors == 1) return floors;
        if(eggs == 1) return floors;
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        int ans = INT_MAX;
        for(int k = 1; k<=floors; k++){
            int mini = 1 + max(helper(eggs-1, k-1), helper(eggs, floors-k)); 
            ans = min(ans, mini);  
        }
        return dp[eggs][floors] = ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return helper(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends