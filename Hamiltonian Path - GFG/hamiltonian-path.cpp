//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int n;
    vector<bool> vis;
    bool dfs(int node,int covered,vector<int> g[]){
        vis[node]=true;
        for(int child:g[node]){
            if(!vis[child]){
                if(dfs(child,covered+1,g))
                    return true;
            }
        }
        vis[node]=false;
        return covered==n;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
       n=N;
        vector<int> g[n+1];
        vis.resize(n+1,false);
        for(auto node:Edges){
            g[node[0]].push_back(node[1]);
            g[node[1]].push_back(node[0]);
        }
        for(int i=1;i<=n;i++){
            if(dfs(i,1,g))
                return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends