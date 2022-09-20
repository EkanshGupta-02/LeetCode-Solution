class Solution {
    int solve(vector<int>&arr,int k,int idx,vector<int>&dp){
        if(idx==arr.size()){
            return 0;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        int ans = -1;
        int maxi = -1;
        
        for(int i = idx;i<arr.size() && i<idx+k;i++){
            maxi = max(maxi,arr[i]);
            ans = max(ans,maxi*(i-idx+1) + solve(arr,k,i+1,dp));
        }
        
        return dp[idx] = ans;
    }
    int solvetab(vector<int>&arr,int k){
        int n = arr.size();
        vector<int>dp(arr.size()+1,0);
        
        for(int idx=n-1;idx>=0;idx--){
            int ans = -1;
            int maxi = -1;
        
            for(int i = idx;i<arr.size() && i<idx+k;i++){
                maxi = max(maxi,arr[i]);
                ans = max(ans,maxi*(i-idx+1) + dp[i+1]);
            }

            dp[idx] = ans;
        }
        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       //  vector<int>dp(arr.size()+1,-1);
       // return solve(arr,k,0,dp);
        return solvetab(arr,k);
    }
};