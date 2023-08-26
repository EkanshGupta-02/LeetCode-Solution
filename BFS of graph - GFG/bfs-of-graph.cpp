//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&ans){
        vis[node] = 1;
        queue<int>q;
        
        q.push(node);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            ans.push_back(top);
            
            for(auto it:adj[top]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                } 
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       
       vector<int>ans;
       bfs(0,adj,vis,ans);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends