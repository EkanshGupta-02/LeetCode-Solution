//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.size() != str2.size()){
            return 0;
        }
        if(str1.size() ==1){
            return str1[0]==str2[0];
        }
        string temp  = str1.substr(0,2);
        string newstr = (str1.substr(2,(int)str1.size()-2)+temp);
        string newstr2 = (str1.substr(str1.size()-2,2) + str1.substr(0,(int)str1.size()-2));
        // cout<<newstr<<endl;
        // cout<<newstr2<<endl;
        return str2==newstr || str2==newstr2;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends