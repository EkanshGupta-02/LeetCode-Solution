class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        string str="";
        while(n+m>=str.length() && str.find(b)==-1){
            str+=a;
        }
        
        if(str.find(b)!=-1){
            return str.length()/n;
        }
        
        return -1;      
    }
};