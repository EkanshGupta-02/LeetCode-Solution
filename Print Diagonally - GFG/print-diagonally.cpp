//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{   
	 vector<int> res;
		for(int k=0;k<n;k++){
		    int i=0,j=k;
		    while(i<n and j>=0) res.push_back(A[i++][j--]);
		}
		for(int k=1;k<n;k++){
		    int i=k,j=n-1;
		     while(i<n and j>=0) res.push_back(A[i++][j--]);
		}
		return res;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends