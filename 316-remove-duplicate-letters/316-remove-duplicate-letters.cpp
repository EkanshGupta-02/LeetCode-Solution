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
//         int len = s.size();
//         string res = "";
//         unordered_map<char, int> M;
//         unordered_map<char, bool> V;
//         stack<int> S;
        
//         for (auto c : s) {
//             if (M.find(c) == M.end()) M[c] = 1;
//             else M[c]++; 
//         }
//         for (unordered_map<char, int>::iterator iter=M.begin(); iter!=M.end(); iter++) 
//             V[iter->first] = false;
        
//         // cout<<M.size()<<V.size()<<endl;
//         for (int i=0; i<len; i++) {
//             M[s[i]]--;
//             if (V[s[i]] == true) continue;
            
//             while (!S.empty() and s[i] < s[S.top()] and M[s[S.top()]] > 0) {
//                 V[s[S.top()]] = false;
//                 S.pop();
//             }
//             S.push(i);
//             V[s[i]] = true;
//         }
//         while (!S.empty()) {
//             res = s[S.top()] + res;
//             S.pop();
//         }
//         return res;
    }
};