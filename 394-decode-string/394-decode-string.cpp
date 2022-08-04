class Solution {
public:
    bool isDigit(char ch){
        if('0'<= ch && ch <='9') return true;
        
        return false;
    }
    bool isChar(char ch){
        if('a'<= ch && ch <= 'z') return true;
        
        return false;
    }
    string solve(string str){
        int n=str.length();
        string ans;
        
        for(int i=0;i<n;i++){
            if(isChar(str[i])){
                ans.push_back(str[i]);
            }
            
            else if (isDigit(str[i])){
                int val = str[i]-'0';
                int j = i+1;
                while(j<n && isDigit(str[j])){
                    val = val*10 + (str[j]-'0');
                    j++;
                }
                if(j>=n) break;
                
                i=j;
                
                int cnt=0;
                
                do{
                    cnt += (str[j]=='[');
                    cnt -= (str[j]==']');
                    j++;
                }while(cnt!=0);
                
                string tempans = solve(str.substr(i+1,(j-1)-(i+1)));
                
                while(val--){
                    ans+=tempans;
                }
                i=j-1;
            }
        }
        
        return ans;
    }
    string decodeString(string s) {
        return solve(s);
    }
};