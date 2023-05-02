//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        int n = s.length();
        stack<char>st;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='+' || s[i]=='*' || s[i]=='-' || s[i]=='/'){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                bool flag = false;
                while(st.top()!='('){
                    if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/') flag =  true;
                    st.pop();
                }
                st.pop();
                if(!flag) return 1;
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends