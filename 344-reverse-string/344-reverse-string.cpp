class Solution {
public:
    void reverseString(vector<char>& s) {
        // int i=0;
        // int e=s.size()-1;
        // while(i<=e){
        // swap(s[i],s[e]);
        //     i++;
        //     e--;
        
        stack<char>ans;
        
        for(int i=0;i<s.size();i++){
            ans.push(s[i]);
        }
        
        for(int i=0;i<s.size();i++){
            char ch=ans.top();
            ans.pop();
            s[i]=ch;
        }
            
    }
};