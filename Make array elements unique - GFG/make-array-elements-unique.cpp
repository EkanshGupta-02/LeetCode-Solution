//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
       unordered_set<int>st;
       long long int cnt = 0;
       for(int i=0;i<N;i++){
           if(st.empty()){
               st.insert(arr[i]);
           }
           else if(st.find(arr[i])!=st.end()){
               while(st.find(arr[i])!=st.end()){
                   arr[i]++;
                   cnt++;
               }
               st.insert(arr[i]);
           }
           else{
               st.insert(arr[i]);
           }
       }
       
       return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends