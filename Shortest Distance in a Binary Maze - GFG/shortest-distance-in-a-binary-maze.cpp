//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source.first == destination.first && source.second == destination.second) return 0;
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
         int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int dis =  q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == destination.first && ncol== destination.second) return 1+dis;
                    q.push({1+dis,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends