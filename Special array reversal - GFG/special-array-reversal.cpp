//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool ischar(char ch){
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
    }
    string reverse(string str)
    { 
         int n=str.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
            {
                st.push(str[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
            {
                str[i]=st.top();
                st.pop();
            }
        }
        return str; 
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends