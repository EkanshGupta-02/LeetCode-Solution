class Solution {
public:
    void helper(vector<string>&ans,string& temp,string& digits,int index,unordered_map<char,string>&mp){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
            }
        
        string str=mp[digits[index]];
        
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            helper(ans,temp,digits,index+1,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        vector<string>ans;
        
        string temp;
        
        if(digits.size()==0){
            return ans;
        }
        
        helper(ans,temp,digits,0,mp);
        
        return ans;
    }
};