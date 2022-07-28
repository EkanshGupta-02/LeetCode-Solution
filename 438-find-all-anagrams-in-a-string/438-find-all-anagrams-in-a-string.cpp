class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        
        vector<int>ans;
        
        int n=s.size();
        int m=p.size();
        
        if(n<m){
            return ans;
        }
        
        int low=0;
        int it=0;
        
        while(it<m){
            shash[s[it]-'a'] += 1;
            phash[p[it]-'a'] += 1;
            it++;
        }
        
        it--;
        
        while(it < n){
            if(shash == phash) ans.push_back(low);
            it+=1;
            if(it != n){
                shash[s[it]-'a'] += 1;
                shash[s[low]-'a'] -= 1;
            }
            low++;
        }
        
        return ans;
    }
};