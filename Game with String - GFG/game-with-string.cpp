//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
          if(s.size() == k)
        {
            return 0;
        }
        
        priority_queue<int> PQ;
        int Arr[26] = {0};
        for(auto i : s)
        {
            Arr[i - 'a'] += 1;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(Arr[i] != 0)
            {
                PQ.push(Arr[i]);
            }
        }
        
        int Ans = 0;
        for(int i = 0; i < k; i++)
        {
            if(PQ.top() == 0)
            {
                return Ans;
            }
            int Ele = PQ.top() - 1;
            PQ.pop();
            PQ.push(Ele);
        }
        
        while(!PQ.empty())
        {
            Ans += PQ.top() * PQ.top();
            PQ.pop();
        }
        
        return Ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends