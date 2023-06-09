//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    void dfs(int r,int c,vector<vector<int>> &grid,int val)
    {
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0||(grid[r][c] > 1 && grid[r][c] < val))
           return ;
           
           grid[r][c]=val;
           dfs(r-1,c,grid,val+1);
           dfs(r,c+1,grid,val+1);
           dfs(r+1,c,grid,val+1);
           dfs(r,c-1,grid,val+1);
           
           
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        // Code here
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    dfs(i,j,grid,2);
                }
                
            }
            
        }
         int minu=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) 
                return -1;
                else if(grid[i][j]>=2)
                minu=max(minu,grid[i][j]);
            }
        }
        return minu-2;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends