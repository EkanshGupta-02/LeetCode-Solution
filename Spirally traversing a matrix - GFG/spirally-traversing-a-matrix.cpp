//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
   vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int row=0, col=0;
        
        int step=1;
        int maxstep=min(r,c);                // number of times increment and decrement operation to be performed
        int flag=1;                                               // flag=1 means moving towards last row and column
        vector<int> ans;
        int i=0,j;
        
        while (step<=maxstep) {                         // Debugging for r=c=4
            if (flag) {
                for (j=i; j<c-col; j++) {                      // j=0-3,i=0||-> j=1-2,i=1
                    ans.push_back(matrix[i][j]);
                }
                j--;
                for (i=i+1; i<r-row; i++) {                 // j=3,i=1-3||-> j=2,i=2
                    ans.push_back(matrix[i][j]);
                }
                i--;                                                  // i=3||-> i=2
                row++;                                           // row=1||-> row=2
                flag=0;
                step++;                                          // step=2||-> step=4
            }
            else {
                for (j=j-1; j>=col; j--) {                    // j=2-0,i=3||-> j=1,i=2
                    ans.push_back(matrix[i][j]);
                }
                j++;                                    
                for (i=i-1; i>=row; i--) {                   // j=0,i=2-1||-> j=1
                    ans.push_back(matrix[i][j]);
                }
                i++;                                    
                col++;
                flag=1;
                step++;                                         // i=1,col=1,step=3||-> i=2,col=2,step=5
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends