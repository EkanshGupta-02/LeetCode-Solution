//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
        
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(n+1,1e9),parent(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        
        dist[1] = 0;
        
        pq.push({0,1});
        while(!pq.empty()){
            int node = pq.top().second;
            int ndist = pq.top().first;
            
            pq.pop();
                for(auto it:adj[node]){
                    int adjnode = it.first;
                    int elwt = it.second;
                    
                    if(ndist + elwt < dist[adjnode]){
                        dist[adjnode] = ndist + elwt;
                        pq.push({ndist + elwt,adjnode});
                        parent[adjnode] = node;
                    }
                }
        }
        
        if(dist[n]==1e9) return{-1};
        
        vector<int>ans;
        int node = n; 
        
        while(parent[node]!=node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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