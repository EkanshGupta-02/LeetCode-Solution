//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    bool isPalindrome(string str){
        int n=str.length();
        
        int i=0,j=n-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string S,int start,vector<string> &temp,vector<vector<string>> &ans){
        int n=S.length();
        
        if(start>=n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start;i<n;i++){
            string prefix=S.substr(start,i-start+1);
            
            if(isPalindrome(prefix)){
                temp.push_back(prefix);
                
                //recursive call
                solve(S,i+1,temp,ans);
                
                //backtrack
                temp.pop_back();
            }
        }
    }
    
  public:
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        
        if(S.length()==0){
            return ans;
        }
        
        int start=0;
        vector<string> temp;
        
        solve(S,0,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends