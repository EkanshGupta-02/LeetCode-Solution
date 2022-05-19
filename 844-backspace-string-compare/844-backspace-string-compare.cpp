class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        for(int i=0;i<s.size();i++){
             if(i==0 && s[i]=='#'){
                continue;
            }
            if(s[i]=='#' && s1.size()!=0){
                s1.pop_back();
            }
            else if(s[i]=='#' && s1.size()==0){
                continue;
            }
            else{
                s1.push_back(s[i]);
            }
        }
        
        string s2="";
        for(int i=0;i<t.size();i++){
            if(i==0 && t[i]=='#'){
                continue;
            }
            else if(t[i]=='#' && s2.size()!=0){
                s2.pop_back();
            }
            else if(t[i]=='#' && s2.size()==0){
                continue;
            }
            else{
                s2.push_back(t[i]);
            }
        }
        
        if(s1.size()!=s2.size()){
            return false;
        }
        
        return s1==s2;
            
    }
};