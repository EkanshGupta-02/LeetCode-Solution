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
    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return solve(satisfaction,0,0,dp);
    }
};