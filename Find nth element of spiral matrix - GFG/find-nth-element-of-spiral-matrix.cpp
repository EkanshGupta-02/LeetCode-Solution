//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int A[MAX][MAX], int n, int m, int k)
{
    int rs = 0,re = n-1;
    int cs = 0,ce = m-1;
    
    int cnt = 0;
    
    while(cnt<k){
        for(int i=cs;i<=ce;i++){
            cnt++;
            if(cnt==k){
                return A[rs][i];
            }
        }
        rs++;
        for(int i=rs;i<=re;i++){
            cnt++;
            if(cnt==k){
                return A[i][ce];
            }
        }
        ce--;
        for(int i=ce;i>=cs;i--){
            cnt++;
            if(cnt==k){
                return A[re][i];
            }
        }
        re--;
        for(int i=re;i>=rs;i--){
            cnt++;
            if(cnt==k){
                return A[i][cs];
            }
        }
        cs++;
    }
    
    return -1;
}

