//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int>&v1,vector<int>&v2,int n)
    {
        // Code here
        vector<vector<int>> visited(n+1,vector<int>(n+1,0));
        
        int si=v1[0];
        int sj=v1[1];
        
        int di=v2[0];
        int dj=v2[1];
        
        queue<vector<int>> q;
        vector<int> v;
        v.push_back(si);
        v.push_back(sj);
        v.push_back(0);
        visited[si][sj]=1;
        q.push(v);
        int dist=INT_MAX;
        
        while(q.size()!=0)
        {
            vector<int> temp=q.front();
            q.pop();
            
            int i=temp[0];
            int j=temp[1];
            int k=temp[2];
            
            if(i==di && j==dj && k<dist)
            dist=k;
            
            if(i+2<=n && j+1<=n && visited[i+2][j+1]==0)
            {
                 vector<int> v;
                 v.push_back(i+2);
                 v.push_back(j+1);
                 v.push_back(k+1);
                 visited[i+2][j+1]=1;
                 q.push(v);
            }
            if(i-2>=0 && j+1<=n && visited[i-2][j+1]==0)
            {
                 vector<int> v;
                 v.push_back(i-2);
                 v.push_back(j+1);
                 v.push_back(k+1);
                 visited[i-2][j+1]=1;
                 q.push(v);
            }
            if(i+2<=n && j-1>=0 && visited[i+2][j-1]==0)
            {
                 vector<int> v;
                 v.push_back(i+2);
                 v.push_back(j-1);
                 v.push_back(k+1);
                 visited[i+2][j-1]=1;
                 q.push(v);
            }
            if(i-2>=0 && j-1>=0 && visited[i-2][j-1]==0)
            {
                 vector<int> v;
                 v.push_back(i-2);
                 v.push_back(j-1);
                 v.push_back(k+1);
                 visited[i-2][j-1]=1;
                 q.push(v);
            }
            if(i+1<=n && j+2<=n && visited[i+1][j+2]==0)
            {
                 vector<int> v;
                 v.push_back(i+1);
                 v.push_back(j+2);
                 v.push_back(k+1);
                 visited[i+1][j+2]=1;
                 q.push(v);
            }
            if(i+1<=n && j-2>=0 && visited[i+1][j-2]==0)
            {
                 vector<int> v;
                 v.push_back(i+1);
                 v.push_back(j-2);
                 v.push_back(k+1);
                 visited[i+1][j-2]=1;
                 q.push(v);
            }
            if(i-1>=0 && j+2<=n && visited[i-1][j+2]==0)
            {
                 vector<int> v;
                 v.push_back(i-1);
                 v.push_back(j+2);
                 v.push_back(k+1);
                 visited[i-1][j+2]=1;
                 q.push(v);
            }
            if(i-1>=0 && j-2>=0 && visited[i-1][j-2]==0)
            {
                 vector<int> v;
                 v.push_back(i-1);
                 v.push_back(j-2);
                 v.push_back(k+1);
                 visited[i-1][j-2]=1;
                 q.push(v);
            }
        }
        
        if(dist==INT_MAX)
        return -1;
        return dist;
    }


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends