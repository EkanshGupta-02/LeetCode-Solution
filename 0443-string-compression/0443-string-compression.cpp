class Solution {
public:
    int compress(vector<char>& chars) {
               int i=0;
        int ansindex=0;
        
        int n=chars.size();
        
        while(i<n){
            
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            
            chars[ansindex++]=chars[i];
            int cnt=j-i;
            
            if(cnt>1){
                string num=to_string(cnt);
                for(char ch:num){
                    chars[ansindex++]=ch;
                }
            }
            i=j;
        }
        
        return ansindex;
    }
};