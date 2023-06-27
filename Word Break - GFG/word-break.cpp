//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
        int solve(int index , string A , vector<string> &B , vector<int>& dp){
        
            if(index >= A.size()) return 1;
            
            if(dp[index] != -1) return dp[index] ;
            
            int ans = 0 ;
            for(int k=index ; k<A.size() ; k++){
                
                    string temp = A.substr(index , k-index+1);
                    
                    if(find(B.begin() , B.end() , temp) != B.end()){
                        
                            ans = ( ans || solve(k+1 , A , B , dp) ) ;
                    }
            }
            
            return dp[index] =  ans ;
    }

    int wordBreak(string A, vector<string> &B) {


        vector<int> dp(A.size()+1 , -1) ;
        return solve(0 , A , B , dp) ;


    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends