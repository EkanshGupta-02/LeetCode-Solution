class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1="";
        string str2="";
        
        for(auto s:word1){
            str1+=s;
        }
        
        for(auto st:word2){
            str2+=st;
        }
        
        return str1==str2;
    }
};