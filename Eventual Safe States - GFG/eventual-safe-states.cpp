//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,int V,vector<int>adj[],vector<int>&check,vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        check[node]=0;
        pathvis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,V,adj,check,vis,pathvis)==true){
                    check[node]=0;
                    return true;
                }
            }
                else if(pathvis[it]){
                    check[node]=0;
                    return true;
                }
        }
        
        check[node]=1;
        pathvis[node]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,V,adj,check,pathvis,vis);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]==1) ans.push_back(i); 
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends