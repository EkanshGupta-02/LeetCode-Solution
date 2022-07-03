class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int cnt=0;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
                st.push(s[i]);
                if(cnt>=2){
                    ans.push_back(s[i]);
                }
            }
            else{
                if(s[i]==')' && cnt>=2){
                    if(st.top()=='('){
                        ans+=')';
                        cnt--;
                        st.pop();
                    }
                }
                else if(cnt==1){
                    st.pop();
                    cnt--;
                }
            }
        }
        
        return ans;
    }
};