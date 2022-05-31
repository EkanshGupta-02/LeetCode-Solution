class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(s.size()<k){
            return false;
        }
        
        unordered_set<string>ans;
        
        for(int i=0;i<=s.length()-k;i++){
            string temp=s.substr(i,k);
            ans.insert(temp);
            }
        
        return ans.size()==pow(2,k);
    }
};