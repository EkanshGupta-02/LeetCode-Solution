class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& first,const string& second){
            return first.size()<second.size();
            });
        
        unordered_map<string,int>mp;
        
        int ans=0;
        
        for(auto word:words){
            int tmplong=0;
            
            for(int i=0;i<word.length();i++){
                string sub=word.substr(0,i)+word.substr(i+1,word.length()+1);
                tmplong=max(tmplong,mp[sub]+1);
            }
            
            mp[word]=tmplong;
            ans=max(ans,tmplong);
        }
        
        return ans;
    }
};