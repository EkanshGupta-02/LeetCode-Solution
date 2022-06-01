class Solution {
public:
    bool isvalid(string s){
        if(s[0]=='1' || s[0]=='2' && s[1]<'7'){
            return true;
        }
        return false;
    }
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int total=1;
        int singleatend=1;
        
        for(int i=1;i<s.length();i++){
            if(s[i]=='0'){
                if(isvalid(s.substr(i-1,2))){
                    total=singleatend;
                    singleatend=0;
                }
                else{
                    return 0;
                }
            }
            else{
                if(isvalid(s.substr(i-1,2))){
                    int curr;
                    curr=total+singleatend;
                    singleatend=total;
                    total=curr;
                }
                else{
                    singleatend=total;
                }
            }
        }
        
        return total;
    }
};