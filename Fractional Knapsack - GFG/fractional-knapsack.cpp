//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{

    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item>a,pair<double,Item>b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>>ans;
        
        for(int i=0;i<n;i++){
            double val = (1.0*arr[i].value)/arr[i].weight;
            pair<double,Item> p = make_pair(val,arr[i]);
            ans.push_back(p);
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        double totval  = 0;
        
        for(int i=0;i<n;i++){
            if(ans[i].second.weight > W){
                totval += W*ans[i].first;
                W=0;
            }
            else{
                totval += ans[i].second.value;
                W = W - ans[i].second.weight;
            }
        }
        
        return totval;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends