class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int j=s.length()-1;
        
        while(s[j]==' '){
            s.pop_back();
            j--;
        }
        
        int i=0;
        int cnt=0;
        
        while(s[i]!='\0'){
            cnt++;
            if(s[i]==' '){
                cnt=0;
            }
            i++;
        }
        
        return cnt;
    }
};