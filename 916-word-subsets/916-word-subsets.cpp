class Solution {
public:
    vector<int> frequent(string str){
        vector<int> freq(26,0);
        for(int i = 0; i < str.length(); i++)
        {
            freq[str[i] - 'a']++;
        }
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>freqword2(26,0);
        
        for(auto x:words2){
            vector<int> freq = frequent(x);
            for(int i = 0; i < 26; i++)
            {
                freqword2[i] = max(freq[i], freqword2[i]);  // upadate freq to max freq
            }
        }
        
        for(auto &x:words1){
            vector<int> freq = frequent(x);
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(freq[i]<freqword2[i]){
                    flag=false;
                    break;
                }  // upadate freq to max freq
            }
            
            if(flag){
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};