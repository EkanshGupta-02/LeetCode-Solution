//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	     vector<int>copy=nums;
         unordered_map<int,int>m;
         
         for(int i=0;i<nums.size();i++)
         {
             m[nums[i]]=i;
         }
         
         int c=0;
         sort(copy.begin(), copy.end());
         
         for(int i=0; i<nums.size();i++)
         {
             if(nums[i]!=copy[i])
             {
                 c++;
                 int index=m[copy[i]];
                 m[nums[i]]=index;
                 m[nums[index]]=i;
                 
               //  cout<<index<<" ";
                 swap(nums[i], nums[index]);
                
             }
         }
         return c;
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
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends