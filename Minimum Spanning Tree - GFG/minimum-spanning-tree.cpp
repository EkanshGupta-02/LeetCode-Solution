//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++)
        {
            int u = -1;
            for (int i = 0; i < V; i++)
            {
                if (!mst[i] && (u == -1 || key[i] < key[u]))
                    u = i;
            }
            mst[u] = true;
            for (auto v : adj[u])
            {
                if (!mst[v[0]] && v[1] < key[v[0]])
                {
                    key[v[0]] = v[1];
                    parent[v[0]] = u;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < V; i++)
        {
            sum += key[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends