//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int n,vector<string>&ans,string temp,int row,int col
    ,vector<vector<int>>&vis){
        if(row==n-1 && col==n-1){
            ans.push_back(temp);
            return;
        }
        if(row+1<n && !vis[row+1][col] && m[row+1][col]==1){
            // cout<<temp<<endl;
            vis[row+1][col]=1;
            solve(m,n,ans,temp+'D',row+1,col,vis);
             vis[row+1][col]=0;
        }
        
        if(col-1>=0 && !vis[row][col-1] && m[row][col-1]==1){
            vis[row][col-1]=1;
            solve(m,n,ans,temp+'L',row,col-1,vis);
             vis[row][col-1]=0;
        }
        if(col+1<n && !vis[row][col+1] && m[row][col+1]==1){
            vis[row][col+1]=1;
            solve(m,n,ans,temp+'R',row,col+1,vis);
             vis[row][col+1]=0;
        }
        if(row-1>=0 && !vis[row-1][col] && m[row-1][col]==1){
            vis[row-1][col]=1;
            solve(m,n,ans,temp+'U',row-1,col,vis);
            vis[row-1][col]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
      if(m[0][0]==0){
          return {};
      }
      vector<string>ans;
      vector<vector<int>>vis(n,vector<int>(n,0));
      vis[0][0]=1;
      solve(m,n,ans,"",0,0,vis);
      return ans;
    }
};

    


//{ Driver Code Starts.

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
}
// } Driver Code Ends