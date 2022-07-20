class Solution {
public:
    bool solve(string& str,string& s){
        int pos=1;
        int i=s.find(str[0]);
        
        if(i==-1){
            return false;
        }
        
        while(pos<str.length()){
            i=s.find(str[pos],i+1);
            if(i==-1){
                return false;
            }
            pos++;
        }
        
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        for(auto str:words){
            if(solve(str,s))
               count++;
        }
        
        return count;
    }
};