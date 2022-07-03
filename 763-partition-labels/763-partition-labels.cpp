class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastocc[26];
        
        for(int i=0;i<s.length();i++){
            lastocc[s[i]-'a']=i;
        }
        
        int j=0;
        int anchor=0;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            j=max(j,lastocc[s[i]-'a']);
            if(i==j){
                ans.push_back(i-anchor+1);
                anchor=i+1;
            }
        }
        return ans;
    }
};