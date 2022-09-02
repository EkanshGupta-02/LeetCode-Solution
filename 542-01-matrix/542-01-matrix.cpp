class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m==0) return mat;
        int n = mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
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