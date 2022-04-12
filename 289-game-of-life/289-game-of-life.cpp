class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
      int m=board.size();
        int n=board[0].size(),cnt;
        
        vector<int>X={-1,0,1};
        vector<int>Y={-1,0,1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                cnt=0;
                
                if(board[i][j]==1){
                    cnt--;
                }
                
                for(auto x:X){
                    for(auto y:Y){
                        
                        if(x+i>=0 && y+j>=0 && x+i<=m-1 && y+j<=n-1){
                            
                            
                            if(board[i+x][y+j]==1 || board[i+x][y+j]==-3 || board[i+x][y+j]==-4){
                                cnt++;
                            }
                        }
                        
                    }
                }
                
                if(cnt<2 || cnt>3){
                    board[i][j]==0?board[i][j]=-1:board[i][j]=-3;
                }
                else if(cnt == 2){
                     board[i][j] == 0 ? board[i][j] = -1 : board[i][j] = -4;
                }
                else{
                    board[i][j] == 0 ? board[i][j] = -2 : board[i][j] = -4;
                }
                
                
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == -2)
                    board[i][j] = 1;
                else if(board[i][j] == -3)
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
        } 
    }
};