//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string str){
         vector<int> pos(26, -1);
        for(int i=0; i<str.size(); i++){
            int index = str[i]-'a';
            if(pos[index] == -1)
                pos[index] = i;
        }
        int i, j;
        bool koi_mil_gya=false;
        for( i=0; i<str.size(); i++ ){
            //Check smaller character which appears after it
            for( j=0; j<str[i]-'a' ; j++ ){
                if(pos[j] > pos[str[i]-'a']){
                     koi_mil_gya = true;
                     break;
                }
            }
            if(koi_mil_gya)break;
        }
        if(koi_mil_gya){
            char first = str[i]; 
            char second = 'a' + j;
            for(auto &ch:str )
            {
                if(ch == first)ch = second;
                else if(ch==second)ch = first;
            }
        }
        return str;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends