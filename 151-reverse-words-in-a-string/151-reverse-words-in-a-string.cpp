class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        reverse(s.begin(),s.end());
        string ans="";
        
        string temp="";
        
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' ' && i!=0 && s[i-1]!=' '){
                reverse(temp.begin(),temp.end());
                ans+=temp+' ';
                temp="";
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        
        bool flag=true;
        int j=ans.length()-1;
        while(flag){
            if(ans[j]==' '){
                ans.pop_back();
                j--;
            }
            else{
                flag=false;
            }
        }
        
        return ans;
        
    }
};