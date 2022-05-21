class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        set<char>st;
        int j=0;
        
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }
            else{
                while(st.find(s[i])!=st.end()){
                    st.erase(s[j]);
                    j++;
                }
                st.insert(s[i]);
            }
            
            if(ans<st.size()){
                ans=st.size();
            }
        }
        
        return ans;
    }
};