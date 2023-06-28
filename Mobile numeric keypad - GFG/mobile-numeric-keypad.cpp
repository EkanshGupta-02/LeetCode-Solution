//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	map<int,vector<int>> keyReach;
 long long dp[26][10];
    
long long func(int N, int id, int cnum){
    if(id>N){
        return 0;
    }
    
    if(id == N){
        return keyReach[cnum].size();
    }
    if(dp[id][cnum]!=-1) return dp[id][cnum];
    long long ans = 0;
    
    vector<int> keys = keyReach[cnum];
    for(int key: keys){
        ans+=func(N, id+1, key);
    }
    return dp[id][cnum] = ans;
}
 
long long getCount(int N)
{
    if(N==1) return 10;
    memset(dp, -1, sizeof(dp));
    keyReach[0] = {0,8};
    keyReach[1] = {1,2,4};
    keyReach[2] = {1,2,3,5};
    keyReach[3] = {2,3,6};
    keyReach[4] = {1,4,5,7};
    keyReach[5] = {2,4,5,6,8};
    keyReach[6] = {3,5,6,9};
    keyReach[7] = {4,7,8};
    keyReach[8] = {0,5,7,8,9};
    keyReach[9] = {6,8,9};
    
    long long ans = 0;
    for(int i=0;i<=9;i++){
        ans+=func(N,2,i);
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends