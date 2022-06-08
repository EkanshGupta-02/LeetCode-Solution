class Solution {
public:
    bool ans=false;
    void find(vector<vector<char>>&board,string word,int i,int j,int idx,int m,int n){
        
        if(idx==word.size()){
            ans=true;
            return;
        }
        
        // check for up
        if(i-1>=0 && board[i-1][j]==word[idx]){
            char ch=board[i-1][j];
            board[i-1][j]='#';
            find(board,word,i-1,j,idx+1,m,n);
            board[i-1][j]=ch;
        }
         
       //  check for down
        if(i+1<m && board[i+1][j]==word[idx]){
            char ch=board[i+1][j];
            board[i+1][j]='#';
            find(board,word,i+1,j,idx+1,m,n);
            board[i+1][j]=ch;
        }
        
      // check for left
        if(j-1>=0 && board[i][j-1]==word[idx]){
            char ch=board[i][j-1];
            board[i][j-1]='#';
            find(board,word,i,j-1,idx+1,m,n);
            board[i][j-1]=ch;
        }
        
     // check for right
        if(j+1<n && board[i][j+1]==word[idx]){
            char ch=board[i][j+1];
            board[i][j+1]='#';
            find(board,word,i,j+1,idx+1,m,n);
            board[i][j+1]=ch;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char temp=word[0];
                if(board[i][j]==word[0]){
                board[i][j]='#';
                find(board,word,i,j,1,m,n);
                board[i][j]=temp;
                }
            }
        }
        
        return ans;
    }
};