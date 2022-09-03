class Solution {
private:
     void solve(int num,int k,int n,vector<int>&ans){
        if(n==1){
            ans.push_back(num);
            return;
        }
        if(num%10-k>=0){
            solve(num*10+(num%10-k),k,n-1,ans);
        }
        if(k){
            if(num%10+k<10){
                solve(num*10+(num%10+k),k,n-1,ans);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,k,n,ans);
        }
        return ans;
    }
};