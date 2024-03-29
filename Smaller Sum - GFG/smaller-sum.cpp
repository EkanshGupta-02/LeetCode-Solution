//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int>v=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,long long>mp;
        long long sum=0;
        vector<long long>temp;
        mp[arr[0]]=0;
        for(int i=1; i<n; i++){
            sum+=arr[i-1];
            if(arr[i]>arr[i-1]){
                mp[arr[i]]=sum;
            }
            else{
                mp[arr[i]]=mp[arr[i-1]];
            }
        }
        for(int i=0; i<n; i++){
            temp.push_back(mp[v[i]]);
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends