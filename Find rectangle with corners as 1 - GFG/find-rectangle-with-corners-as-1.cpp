//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
       int rows = matrix.size();
       if (rows == 0)
          return false;
       
       int columns = matrix[0].size();
       unordered_map<int, unordered_set<int> > ump;
       for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < columns - 1; ++j) {
             for (int k = j + 1; k < columns; ++k) {
                if (matrix[i][j] == 1 && matrix[i][k] == 1) {
                   if (ump.find(j) != ump.end() && ump[j].find(k) != ump[j].end())
                      return true;
                   if (ump.find(k) != ump.end() && ump[k].find(j) != ump[k].end())
                      return true;
                   ump[j].insert(k);
                   ump[k].insert(j);
                }
             }
          }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 



// } Driver Code Ends