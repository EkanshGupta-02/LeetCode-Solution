class Solution {
public:
    void addsolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        
        ans.push_back(temp);
    }
    bool issafe(vector<vector<int>>&board,int col,int row,int n){
        int x=row;
        int y=col;
        
        while(y>=0){
            if(board[x][y]==1)
                return false;
               y--;
        }
        
        x=row;
        y=col;
        
        while(x>=0 && y>=0){
            if(board[x][y]==1)
                return false;
            x--;
            y--;
        }
        
        x=row;
        y=col;
        
        while(x<n && y>=0){
            if(board[x][y]==1)
                return false;
            x++;
            y--;
        }
        
        return true;
    }
    void solve(vector<vector<int>>&board,vector<vector<int>>&ans,int col,int n){
        if(col==n){
            addsolution(board,ans,n);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(issafe(board,col,i,n)){
                board[i][col]=1;
                solve(board,ans,col+1,n);
                board[i][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
       vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        
        solve(board,ans,0,n);
        
        return ans.size();
    }
};