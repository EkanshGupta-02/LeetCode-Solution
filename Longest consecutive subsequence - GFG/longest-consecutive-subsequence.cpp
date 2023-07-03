//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int maxi=-1, count=0, maxele=-1;
        map<int,int>mp;
        
        for(int i=0; i<N; i++)
            maxele=max(arr[i],maxele);
        
        for(int i=1; i<=maxele; i++)
            mp[i]={0};
        
        for(int i=0; i<N; i++)
            mp[arr[i]]++;
            
        
        for(auto it:mp)
        {
            if(it.second==0)
            {
                maxi=max(count,maxi);
                count=0;
            }
            else
                count++;
        }
        
        return max(count,maxi);
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends