//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        stack<char>st;
        
        for(auto ch:x){
            if(st.empty()){
                st.push(ch);
            }
            else if(st.top()=='(' && ch==')'){
                st.pop();
            }
            else if(st.top()=='[' && ch==']'){
                st.pop();
            }
            else if(st.top()=='{' && ch=='}'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends