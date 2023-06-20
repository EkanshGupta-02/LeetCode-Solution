//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int bellman(int s,int n, vector<vector<int>>edges){
        vector<int>dist(n,1e8);
        dist[s]=0;
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]+wt<dist[v] && dist[u]!=1e8){
                dist[v]=dist[u]+wt;
            }
        }
    }
    
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
            return 1;
        }
    }
    
    return 0;
   }
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	      for(int i=0;i<n;i++)
            if(bellman(i,n,edges)==1)
                return 1;
          return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends