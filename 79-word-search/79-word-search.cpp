class Solution {
public:
    bool ans=false;
    
    void search(vector<vector<char>>& board,int i,int j,string& word,int idx){
        
        //base case
        
        if(idx==word.size()){
            ans=true;
            return;
        }
        
        //Upper check
        if(i-1>=0 && board[i-1][j]==word[idx]){
            char ch=word[idx];
            board[i-1][j]='#';
            search(board,i-1,j,word,idx+1);
            board[i-1][j]=ch;
        }
        
        //Lower Check
        if(i+1 < board.size() && board[i+1][j]==word[idx]){
            char ch=word[idx];
            board[i+1][j]='#';
            search(board,i+1,j,word,idx+1);
            board[i+1][j]=ch;
        }
        
        //Left check
        if(j-1 >= 0 && board[i][j-1]==word[idx]){
            char ch=word[idx];
            board[i][j-1]='#';
            search(board,i,j-1,word,idx+1);
            board[i][j-1]=ch;
        }
        
        //Right check
        if(j+1 < board[0].size() && board[i][j+1]==word[idx]){
            char ch=word[idx];
            board[i][j+1]='#';
            search(board,i,j+1,word,idx+1);
            board[i][j+1]=ch;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=word[0];
                if(board[i][j]==word[0]){
                    board[i][j]='#';
                    search(board,i,j,word,1);
                    board[i][j]=ch;
                }
            }
        }
        
        return ans;
    }
};