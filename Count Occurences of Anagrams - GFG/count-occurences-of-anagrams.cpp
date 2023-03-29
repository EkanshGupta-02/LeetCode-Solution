//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int>shash(26,0),phash(26,0);
	    
	    int cnt=0;
	    
	    int n=pat.size();
	    int m=txt.size();
	    
	    if(m<n) return 0;
	    
	    int it=0,low=0;
	    
	    while(it<n){
	        shash[txt[it]-'a']++;
	        phash[pat[it]-'a']++;
	        it++;
	    }
	    
	    it--;
	    
	    while(it<m){
	        if(shash==phash) cnt++;
	        it++;
	        if(it!=m){
	            shash[txt[it]-'a']++;
	            shash[txt[low]-'a']--;
	        }
	        low++;
	    }
	    
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends