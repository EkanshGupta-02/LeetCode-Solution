//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.

     void solve(int i, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds){
        if(i==arr.size()){
            if(target==0){
                sort(ds.begin(), ds.end());
                ans.push_back(ds);
            }return;
        }

        if(arr[i]<=target){
            ds.push_back(arr[i]);
            solve(i, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }

        solve(i+1, target, arr, ans, ds);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int> newA;
        set<int>t;
        for(auto it:A){
            t.insert(it);
        }
        for(auto it:t){
            newA.push_back(it);
        }
        solve(0, B, newA, ans, ds);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends