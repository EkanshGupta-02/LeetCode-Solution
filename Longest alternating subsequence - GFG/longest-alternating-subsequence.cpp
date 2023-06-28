//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int incr=1;
            int decr=1;
            int ele=nums[0];
            int n=nums.size();
            for(int i=1;i<n;i++)
            {
                if(nums[i]>ele) //there is a sign of increase
                {
                    incr=1+decr;
                    ele=nums[i];
                }
                else if(nums[i]<ele)
                {
                    decr=1+incr;
                    ele=nums[i];
                }
            }
            
            return max(incr,decr);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends