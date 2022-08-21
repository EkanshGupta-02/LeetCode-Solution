class Solution {
private:
void dfs(vector<vector<char>>& grid,int row,int col,int n,int m,vector<vector<int>>& vis){
    vis[row][col]=1;
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    
    for(int i=0;i<4;i++){
        int newrow = row + delrow[i];
        int newcol = col + delcol[i]; 
        
        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol] == '1' && vis[newrow][newcol]!=1){
            dfs(grid,newrow,newcol,n,m,vis);
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
         
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid,i,j,n,m,vis);
                }
            }
        }
        
        return cnt;
    }
};