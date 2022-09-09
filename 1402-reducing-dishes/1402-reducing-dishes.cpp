class Solution {
private:
    int solve(vector<int>& arr,int time,int index,vector<vector<int>>&dp){
        if(index==arr.size()){
            return 0; 
        }
        
        if(dp[time][index]!=-1) return dp[time][index]; 
        
        int taken = arr[index]*(time+1) + solve(arr,time+1,index+1,dp);
        int nottaken = solve(arr,time,index+1,dp);
        
        return dp[time][index]= max(taken,nottaken);
    }
    int solvetab(vector<int>&arr){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int index=n-1;index>=0;index--){
            for(int time = index;time>=0;time--){
          int taken = arr[index]*(time+1) + dp[time+1][index+1];
          int nottaken = dp[time][index+1];
        
             dp[time][index]= max(taken,nottaken);
            }
        }
        
        return dp[0][0];
    }
    int solvetabSO(vector<int>&arr){
        int n = arr.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        for(int index=n-1;index>=0;index--){
            for(int time = index;time>=0;time--){
          int taken = arr[index]*(time+1) + next[time+1];
          int nottaken = next[time];
        
            curr[time]= max(taken,nottaken);
            }
            next=curr;
        }
        
        return next[0];
    }
    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>>dp(n+1,vector<int>(n,-1));
        // return solve(satisfaction,0,0,dp);
        return solvetabSO(satisfaction);
    }
};