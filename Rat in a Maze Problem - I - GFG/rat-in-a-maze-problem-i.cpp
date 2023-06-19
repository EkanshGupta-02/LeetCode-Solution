// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int i,int j,int row,int col,vector<vector<int>> &arr,vector<vector<bool>>& visited){
        if(((i>=0) && (i<row)) && ((j>=0) && (j<col)) && ((arr[i][j]==1) && (visited[i][j]==false))) {
          return true;      
        }
    
        return false;
    }
    
    void solveMaz(vector<vector<int>> &arr,int row,int col,int i,int j,vector<vector<bool>>& visited, vector<string>&path, string output){
        //base
        if( i==row-1 && j==col-1){
            path.push_back(output);
            return;
        }
    
        //Down 
        if(isSafe(i+1,j,row,col,arr,visited)) {
            visited[i+1][j]=true;
            solveMaz(arr,row,col,i+1,j,visited,path,output+'D');
            //backtracking 
            visited[i+1][j]=false;  
        }
        
        //Left
        if(isSafe(i,j-1,row,col,arr,visited)) {
            visited[i][j-1]=true;
            solveMaz(arr,row,col,i,j-1,visited,path,output+'L');
            //backtracking 
            visited[i][j-1]=false;  
        }
    
        //Right
        if(isSafe(i,j+1,row,col,arr,visited)) {
            visited[i][j+1]=true;
            solveMaz(arr,row,col,i,j+1,visited,path,output+'R');
            //backtracking 
            visited[i][j+1]=false;  
        }
    
        //Up
        if(isSafe(i-1,j,row,col,arr,visited)) {
            visited[i-1][j]=true;
            solveMaz(arr,row,col,i-1,j,visited,path,output+'U');
            //backtracking 
            visited[i-1][j]=false;  
        }
    
    }
        
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int row=n,col=n;
    
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        visited[0][0]=true;
        
        vector<string>path;
        string output="";
        
        if(m[0][0]==0)
            return path;
    
        solveMaz(m,row,col,0,0,visited,path,output);
        
        return path;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends