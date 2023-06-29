//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    double compute(tuple<int,int,int>l, vector<pair<int,int>>p, int n,double X){
        double res= 0;
        double Y = -1*( get<2>(l)+get<0>(l)*X)/get<1>(l);
        for(int i=0; i<n; i++){
            res+=sqrt( (X-p[i].first)*(X-p[i].first)+(Y-p[i].second)*(Y-p[i].second) );
        }
        return res;
    }
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
        //Write your code here
           double low = -1e6;
           double high = 1e6;
           double eps = 1e-6 ;//aise hi smallest  +ve number 
          //taki loop tab end ho jab low & high almost equal ho jaye 
        while( (high-low)>eps ){
            double mid1 = low+(high-low)/3;
            double mid2 = high -(high-low)/3;
            double dts1 = compute(l,p,n,mid1);
            double dts2 = compute(l,p,n,mid2);
           if(dts1>dts2){
               low = mid1;
           }
           else high = mid2;
        }
       return compute(l,p,n,(low+high)/2);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends