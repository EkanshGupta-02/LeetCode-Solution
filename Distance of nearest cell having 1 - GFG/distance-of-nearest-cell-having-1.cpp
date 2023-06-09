//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
	    
	    queue<pair<int,int>>q;
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                dist[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	   int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

	    
	    while(!q.empty()){
	        pair<int,int>front = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow = front.first + dir[i][0];
                int newcol = front.second + dir[i][1];
                
                 if (newrow >= 0 && newrow < m && newcol>=0 && newcol < n) {
                    if (dist[newrow][newcol] > dist[front.first][front.second] + 1) {
                        dist[newrow][newcol] = dist[front.first][front.second] + 1;
                        q.push({newrow,newcol});
                    }
                }
            }
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends