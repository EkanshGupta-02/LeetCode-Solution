class Solution {
public:
    string removeDuplicateLetters(string s) {
    int size = s.size();
            
        string res = "";
            
        unordered_map<char,int>freq;
            
        unordered_map<char,bool>vis;
           
        stack<int>st;
    
        for(auto ch:s){
                freq[ch]++;
            }
        for (unordered_map<char, int>::iterator iter=freq.begin(); iter!=freq.end(); iter++) 
               vis[iter->first] = false;
        
        for(int i=0;i<size;i++){
            freq[s[i]]--;
            if(vis[s[i]]) continue;
            
            while(!st.empty() && s[i]<s[st.top()] && freq[s[st.top()]]>0){
                vis[s[st.top()]]=false;
                st.pop();
            }
            st.push(i);
            vis[s[i]]=true;
        }
        
        while(!st.empty()){
            res += s[st.top()];
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};