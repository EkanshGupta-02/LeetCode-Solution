//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
   static bool compare(struct val v1, struct val v2){
        return v1.second < v2.second;
    }

    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
    
        sort(p,p+n,compare);
        int answer = 1;
        int lastValue = p[0].second;
        
        for(int i=1;i!=n;i++){
            if(p[i].first > lastValue){
                answer++;
                lastValue = p[i].second;
            }
        }
        return answer;
        
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends