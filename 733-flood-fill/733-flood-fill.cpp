class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&image, vector<vector<int>>& ans,int newcolor,int inicolor,int delrow[],int delcol[]){
        ans[row][col]=newcolor;
        int n=image.size();
        int m = image[0].size();
        
        
        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && image[newrow][newcol]==inicolor && ans[newrow][newcol]!=newcolor){
                dfs(newrow,newcol,image,ans,newcolor,inicolor,delrow,delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        
        int delrow[] = {0,1,0,-1};
        int delcol[] = {-1,0,1,0};
                                   
        int initialcolor = image[sr][sc];
                                   
                                   
        dfs(sr,sc,image,ans,color,initialcolor,delrow,delcol);
                                   
        return ans;
    }
};