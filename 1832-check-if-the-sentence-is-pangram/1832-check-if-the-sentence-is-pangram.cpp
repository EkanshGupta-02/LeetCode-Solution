class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26,0);
        for(auto ch:sentence){
            int index = ch - 'a';
            v[index]++;
        }
        
        for(auto num:v){
            if(num==0){
                return false;
            }
        }
        return true;
    }
};