class Solution {
public:
    bool check(string str){
        unordered_map<char,int>mp;
        for(auto ch:str){
            if(mp.find(ch)==mp.end()){
                mp[ch]=1;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    void solve(string str,vector<string>&arr,int idx,int& maxi){
        if(idx==arr.size()){
            return;
        }
        
        if(check(arr[idx])==false){
            return solve(str,arr,idx+1,maxi);
        }
        
        for(int i=idx;i<arr.size();i++){
            string temp = str+arr[i];
            if(check(temp)){
                maxi = max(maxi,(int)temp.length());
                solve(temp,arr,i+1,maxi);
            }
        }
    }
    int maxLength(vector<string>& arr) {
       int maxi = INT_MIN;
        solve("",arr,0,maxi);
        
        return maxi==INT_MIN?0:maxi;
    }
};