//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        if(n < 3) return n;
        long long prev2 = 1,prev1 = 2,ans,mod = 1e9+7;
        for(int i = 2;i < n;i++){
            ans = (prev1+(prev2*i))%mod;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends