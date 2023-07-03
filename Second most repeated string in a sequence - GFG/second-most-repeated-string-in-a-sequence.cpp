//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        
        if(m.size()==1){
            string temp;
            return temp;
        }
        
        int maxi1=INT_MIN;
        
        for(auto i:m){
            if(i.second>maxi1){
                maxi1=i.second;
            }
        }
        
        for(auto i:m){
            if(i.second==maxi1){
                m[i.first]=-1;
            }
        }
        
        int maxi2=INT_MIN;
        
        for(auto i:m){
            if(i.second>maxi2){
                maxi2=i.second;
            }
        }
        
        for(auto  i:m){
            if(i.second==maxi2){
                return i.first;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends