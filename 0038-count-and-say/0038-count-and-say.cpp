class Solution {
public:
    string help(string st){
        string res = "";
       for(int i=0;i<st.size();i++){
           int j=i+1;
           int cnt = 1;
           while(st[i]==st[j] && j<st.size()){
               cnt++;
               j++;
           }
           res += to_string(cnt) + st[i];
           i=j-1;
       } 
        return res;
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
       string ans="1";
        
        for(int i=2;i<=n;i++){
            string temp = help(ans);
            ans = temp;
        }
        
        return ans;
    }
};