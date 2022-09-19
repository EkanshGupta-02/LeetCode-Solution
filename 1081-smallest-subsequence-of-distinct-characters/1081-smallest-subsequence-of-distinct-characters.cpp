class Solution {
public:
    string smallestSubsequence(string s) {
        int size = s.size();
        unordered_map<char,int>freq;
        unordered_map<char,bool>taken;
        
        stack<int>st;
        
        for(auto ch:s){
            freq[ch]++;
        }
        
        for(int i=0;i<size;i++){
            freq[s[i]]--;
            if(taken[s[i]]) continue;
            
            while(!st.empty() && s[i]<s[st.top()] && freq[s[st.top()]]>0){
                taken[s[st.top()]] = false;
                st.pop();
            }
            
            st.push(i);
            taken[s[i]]=true;
        }
        
        string ans="";
        while(!st.empty()){
            ans += s[st.top()];
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};