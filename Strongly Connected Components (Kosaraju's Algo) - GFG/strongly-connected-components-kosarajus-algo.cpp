//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void topodfs(int node,unordered_map<int,bool>&visited,stack<int>&st,vector<vector<int>>& adj){
	    visited[node]=true;
	    
	    for(auto it:adj[node]){
	        if(!visited[it]){
	            topodfs(it,visited,st,adj);
	        }
	    }
	    
	    st.push(node);
	}
	
	void dfs(int node,unordered_map<int,bool>&newvis,unordered_map<int,list<int>>&adjlist){
	    newvis[node]=true;
	    
	    for(auto it:adjlist[node]){
	        if(!newvis[it]){
	            dfs(it,newvis,adjlist);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        unordered_map<int,bool>visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
            topodfs(i,visited,st,adj);
            }
        }
        
        unordered_map<int,list<int>>adjlist;
        unordered_map<int,bool>newvis;
        
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                adjlist[j].push_back(i);
            }
        }
        
        int cnt=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!newvis[top]){
                dfs(top,newvis,adjlist);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends