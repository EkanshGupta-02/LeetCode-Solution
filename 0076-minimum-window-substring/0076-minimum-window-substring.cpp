class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        
        for(auto ch:t){
            mp[ch]++;
        }
        
        int start=0;
        int ans = INT_MAX;
        
        int cnt = mp.size();
        int i=0;
        int j=0;
        
        while(j<s.length()){
            mp[s[j]]--;
            
            if(mp[s[j]]==0){
                cnt--;
            }
            
            if(cnt==0){
                while(cnt==0){
                    if(ans>j-i+1){
                        ans=min(j-i+1, ans);
                        start=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        cnt++;
                    }
                    i++;
                }
            }
           j++; 
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            
            return "";
    }
};