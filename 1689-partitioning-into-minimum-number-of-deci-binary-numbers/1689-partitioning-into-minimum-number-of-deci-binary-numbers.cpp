class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        
        for(int i=0;i<n.length();i++){
            int t=n[i]-'0';
            mx=max(mx,t);
        }
        
        return mx;
    }
};