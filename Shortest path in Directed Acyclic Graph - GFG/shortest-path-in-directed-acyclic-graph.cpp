//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node,unordered_map<int,int>&vis,unordered_map<int,list<pair<int,int>>>&adj,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            int v = it.first;
            if(!vis[v]){
                dfs(v,vis,adj,st);
            }
        }
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        stack<int>st;
        unordered_map<int,int>vis;
        for(int i=0;i<N;i++)
        {
            if(!vis[i]) {
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int>dist(N);
        for(int i=0;i<N;i++){
            dist[i]=INT_MAX;
        }
        dist[0]=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            for(auto it:adj[top]){
                int v = it.first;
                int wt = it.second;
                if(dist[v]==INT_MAX && dist[top]==INT_MAX)continue;
                if(dist[top]+wt<dist[v]){
                    dist[v] = dist[top] + wt;
                }
            }
        }
        
        for(int i=0;i<N;i++) {
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends