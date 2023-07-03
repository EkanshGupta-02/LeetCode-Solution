//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
      int count1 = 0;
    int count2 = 0;
    
    int i =0;
    while(i<S.length())
    {
        if(S[i]=='1')
        {
            count1++;
        }
        else count2++;
        
        i++;
        if(i>=S.length()) break;
        
        if(S[i]=='0')
        {
            count1++;
        }
        else count2++;
        i++;
    }
    
    return min(count1, count2);
}