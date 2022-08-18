class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int row,int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || visited[row][col] 
           || grid[row][col]==0){
            return 0;
        }
        visited[row][col]=1;
        
        return (1+dfs(grid,visited,row-1,col)+dfs(grid,visited,row,col-1)+dfs(grid,visited,row+1,col)+dfs(grid,visited,row,col+1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){ 
                    maxi = max(maxi , dfs(grid,visited,i,j));
            }
        }
        
        return maxi;
    }
};