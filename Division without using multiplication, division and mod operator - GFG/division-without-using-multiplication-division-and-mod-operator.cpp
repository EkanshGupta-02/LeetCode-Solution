//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
         int sign=1;
        if(dividend<0 || divisor<0)sign=-1;
        if(dividend<0 && divisor<0)sign=1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        long long int quotient=0;
        long long int rest=0;
        for(int i=31;i>=0;i--){
            if(rest+ (divisor<<i) <=dividend){
                rest+=divisor<<i;
                quotient=quotient|(1<<i);
            }
        }
        if(sign<0)return -quotient;
        else return quotient;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends