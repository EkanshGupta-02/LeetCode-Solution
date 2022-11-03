class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto w:words){
            mp[w]++;
        }
        
        int cnt=0;
        bool flag=false;
        
        for(auto word:words){
            string temp = word;
            
            reverse(temp.begin(),temp.end());
            
            if(temp!=word && mp[word] && mp[temp]){
                cnt+=4;
                mp[word]--;
                mp[temp]--;
            }
            
            else if(temp==word && mp[temp]>1){
                cnt += 4;
                mp[temp]-=2;
            }
            else if(temp==word && !flag && mp[temp]>0){
                cnt+=2;
                mp[temp]--;
                flag =true;
            }
        }
        return cnt;
    }
};