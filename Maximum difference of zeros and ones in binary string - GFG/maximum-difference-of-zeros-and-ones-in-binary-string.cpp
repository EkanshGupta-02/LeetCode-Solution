//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	     int s=S.length();
        int count=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='1')
            count++;
        }
        if(s==count)return -1;
       for(int i=0;i<S.length();i++)
       {
           if(S[i]=='1')
           S[i]=-1;
           if(S[i]=='0')
           S[i]=1;
       }
       int currsum=0,maxSum=INT_MIN;
       for(int i=0;i<S.length();i++)
       {
           currsum+=S[i];
           if(currsum>=maxSum)
           maxSum=currsum;
           if(currsum<0)
            currsum=0;
       }
       return maxSum;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends