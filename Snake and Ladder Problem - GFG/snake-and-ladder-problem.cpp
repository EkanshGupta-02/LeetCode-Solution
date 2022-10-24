//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// 
class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int,int>ladder;
        unordered_map<int,int>snake;
        
        for(int i=0;i<2*N;i+=2){
            if(arr[i+1]>arr[i]){
                ladder[arr[i]]=arr[i+1];
            }
            else{
                snake[arr[i]]=arr[i+1];
            }
        }
    
    queue<int>q;
    q.push(1);
    int ans=0;
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                int val = q.front();
                q.pop();
                
                if(val+6>=30){
                    return ans+1;
                }
                
                for(int j=val;j<=val+6;j++){
                    if(ladder.count(j)){
                        q.push(ladder[j]);
                    }
                }
                
                int lasval = val+6;
                while(lasval>0 && snake.count(lasval)){
                    lasval--;
                }
                q.push(lasval);
            }
              ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends