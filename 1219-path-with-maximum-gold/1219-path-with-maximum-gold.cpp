class Solution {
private:
    vector<int> directions={0,1,0,-1,0};
    int dfs(int i,int j,vector<vector<int>> &grid)
    {
        int x,y,temp=grid[i][j],result=0;
        grid[i][j]=0;
        for(int d=0;d<4;d++)           
        {
            x=i+directions[d],y=j+directions[d+1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&grid[x][y]!=0)
                result=max(result,grid[x][y]+dfs(x,y,grid));  
        }
        grid[i][j]=temp;
        return result;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                ans = max(ans,grid[i][j] + dfs(i,j,grid));
            }
        }
        return ans;
    }
};