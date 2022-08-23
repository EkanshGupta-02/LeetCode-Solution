class Solution {
private:
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int row,int col,bool&flag){
        if(row<0 || row>=grid2.size() || col<0 || col>=grid2[0].size()){
            return ;
        }
        
        if(grid2[row][col]==1 && grid1[row][col]!=1){
            flag=false;
        }
        
        if(grid2[row][col]==0) return;
        
        grid2[row][col]=0;
        
        dfs(grid1,grid2,row-1,col,flag);
        
        dfs(grid1,grid2,row,col-1,flag);
        
        dfs(grid1,grid2,row+1,col,flag);
        
        dfs(grid1,grid2,row,col+1,flag);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m  = grid1[0].size();
        
            
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                            bool flag=true;
                    dfs(grid1,grid2,i,j,flag);
                    if(flag) cnt++;
                }
            }
        }
        
        return cnt;
    }
};