//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int lsize = m-l+1;
        int rsize = r-m;
        
        
        int* left = new int[lsize];
        int* right = new int[rsize];
        
        for(int i=0;i<lsize;i++){
            left[i] = arr[l+i];
        }
        for(int i=0;i<rsize;i++){
            right[i] = arr[m+i+1];
        }
        int i=0,j=0,k=l;
        
        while(i<lsize && j<rsize){
            if(left[i]<=right[j]){
                arr[k++] = left[i++];
            }
            else{
                arr[k++] = right[j++];
            }
        }
        
        while(i<lsize){
            arr[k++] = left[i++];
        }
        while(j<rsize){
            arr[k++] = right[j++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
            int mid = l + (r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends