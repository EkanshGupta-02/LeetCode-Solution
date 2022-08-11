class Solution {
public:
    bool solve(string& s,string& t,int i,int j){
        if(i==0)
            return true;
        if(j==0)
            return false;
        
        if(s[i-1]==t[j-1]){
            return solve(s,t,i-1,j-1);
        }
        return solve(s,t,i,j-1);
    }
    bool isSubsequence(string s, string t) {
        if(solve(s,t,s.length(),t.length())){
            return true;
        }
        return false;
    }
};