//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
     int solve(string &a, string &b, string &c, int n1, int n2, int n3,vector<vector<int>>&dp)
    {
        if(n3==0 and n1==0 and n2==0)
        {
            return 1;
        }
       
        if(dp[n1][n2]!=-1)return dp[n1][n2];
        int a1=0;
        int b1=0;
        if(n1-1>=0 and a[n1-1]==c[n3-1])
        {
            a1=solve(a,b,c,n1-1,n2,n3-1,dp);
        }
        if(n2-1>=0 and b[n2-1]==c[n3-1])
        {
            b1=solve(a,b,c,n1,n2-1,n3-1,dp);
        }
        return dp[n1][n2]=(a1 or b1);
    }
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        int n1=A.size();
        int n2=B.size();
        int n3=C.size();
        if(n1+n2!=n3)return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        bool ans=solve(A,B,C,n1,n2,n3,dp);
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends