//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
           int n=str.size();
        int c=0;
        int zeros=0,ones=0;
        for(int i=0; i<n; i++)
        {
            if(str[i]=='0')zeros++;
            if(str[i]=='1')ones++;
            if(zeros==ones)c++;
        }
        if(zeros!=ones) return -1;
        return c;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends