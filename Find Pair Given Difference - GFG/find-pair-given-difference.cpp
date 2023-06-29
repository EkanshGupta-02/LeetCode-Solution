//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int a[], int size, int n){
      sort(a, a+size);
    int i=0, j=0;
    while(j<=size-1){
        if(a[j]-a[i]==n&&i!=j)return true;
        else if(a[j]-a[i]<n)j++;
        else i++;
    }
    return false;
    
}