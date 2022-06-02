class Solution {
public:
    void reverse(vector<char>&s,int st,int en){
        if(st>en){
            return;
        }
        swap(s[st],s[en]);
        st++;
        en--;
        reverse(s,st,en);
    }
    void reverseString(vector<char>& s) {
        // int i=0;
        // int e=s.size()-1;
        // while(i<=e){
        // swap(s[i],s[e]);
        //     i++;
        //     e--;
        
//         stack<char>ans;
        
//         for(int i=0;i<s.size();i++){
//             ans.push(s[i]);
//         }
        
//         for(int i=0;i<s.size();i++){
//             char ch=ans.top();
//             ans.pop();
//             s[i]=ch;
//         }
        
        int st=0;
        int en=s.size()-1;
        
        reverse(s,st,en);
            
    }
};