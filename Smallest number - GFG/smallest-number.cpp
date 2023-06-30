//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int s, int d){
        if(9*d <s){
            return "-1";
        }
        string ans(d,'0');
        int i = d-1;
        int sum = s-1;
        while(1){
            if(sum <= 9){
                ans[i] = ans[i]+sum;
                break;
            }
            sum -= 9;
            ans[i] = ans[i]+9;
            i--;
        }
        ans[0] += 1;
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends