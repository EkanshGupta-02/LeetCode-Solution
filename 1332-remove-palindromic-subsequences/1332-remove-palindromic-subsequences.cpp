class Solution {
public:
    int removePalindromeSub(string s) {
        int j=s.length()-1;
        int i=0;
        
        while(i<j){
            if(s[i]!=s[j]){
                return 2;
            }
            i++;
            j--;
        }
        
        return 1;
    }
};