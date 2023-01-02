//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       int left = 0;
       int right = n-1;
       
       int lmax = 0;
       int rmax = 0;
       
       long long int ans = 0;
       
       while(left<right){
           
           if(arr[left]<arr[right]){
               arr[left]>lmax?(lmax = arr[left]):(ans += lmax - arr[left]);
               left++;
           }
           else{
              arr[right]>rmax?(rmax = arr[right]):(ans += rmax - arr[right]);
              right--;
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends