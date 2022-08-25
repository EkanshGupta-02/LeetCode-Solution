class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        
        for(auto m:magazine){
            mp[m]++;
        }
        
        for(auto r:ransomNote){
            mp[r]--;
            if(mp[r]<0) return false;
        }
        
        return true;
    }
};