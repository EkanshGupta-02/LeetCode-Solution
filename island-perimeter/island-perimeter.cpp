class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int tot= 0, m = grid.size(), n = grid[0].size(), rep = 0;
        
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++) 
                    if(grid[i][j]==1) 
                    {
                        tot++;
                        if(i!=0 && grid[i-1][j]==1) rep++;
                        if(j!=0 && grid[i][j-1]==1) rep++;
                    }
        
        return (4 * tot) - (2 * rep); 
    }
};