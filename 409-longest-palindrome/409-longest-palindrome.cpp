class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        
        int ans=0;
        
        for(auto m:mp){
            ans += m.second/2*2;
            
            if(ans%2==0 && m.second%2==1)ans++;
        }
        
        return ans;
    }
};