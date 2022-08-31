class Solution {
private:
    bool ispalindrome(string& s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>& temp,string& s,int index){
        if(index>=s.length()){
            ans.push_back(temp);
        }
        
        for(int i=index;i<s.length();i++){
            if(ispalindrome(s,index,i)){
                
                 temp.push_back(s.substr(index,i-index+1));
                
                solve(ans,temp,s,i+1);
                
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>temp;
        
        solve(ans,temp,s,0);
        
        return ans;
    }
};