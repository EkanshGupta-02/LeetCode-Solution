class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        
        int n=words.size();
        
        set<string>st;
        
        for(auto i : words){
          string s = i;
          sort(s.begin(),s.end());
        if(st.find(s)==st.end()){
            st.clear(); 
            st.insert(s);
            ans.push_back(i);
        }
    }
        
        return ans;
    }
};