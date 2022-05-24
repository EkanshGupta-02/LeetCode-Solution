class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        
        while(columnNumber){
            columnNumber--;
            ans.push_back(char(65 + columnNumber%26));
            columnNumber=columnNumber/26;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};