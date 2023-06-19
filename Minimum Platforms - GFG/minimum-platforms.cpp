//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
     //firstly we will sort both the given arrays
        sort(arr,arr+n);
        sort(dep, dep+n);
        
        int count=1;       //cnt to find mini number of platforms needed; it will be 1 because atleast 1 platform will be needed to hault
        int j=0;
        
        for(int i=1;i<n;i++){
            if(arr[i]>dep[j]){    //means the 2nd train in coming later
                j++;
            }
            else{
                count++;       //if not then you need another platform
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends