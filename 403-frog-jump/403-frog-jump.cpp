class Solution {
private:
    bool solve(vector<int>&stones,int pos,int prevstep,unordered_map<int,bool>&mp_st,map<pair<int,int>,bool>&dp){
        if(mp_st[pos]==false || pos > stones[stones.size()-1]){
            return false;
        }
        
       if(pos == stones[stones.size()-1]){
           return true;
       }
        
    if(dp.find({pos,prevstep}) != dp.end()) return dp[{pos,prevstep}];
        
        bool ans;
        if(pos==0){
            ans = solve(stones,pos+1,1,mp_st,dp);
        }
        else{
            if(prevstep-1>0) 
               ans = solve(stones,pos+(prevstep-1),prevstep - 1,mp_st,dp);
            if(ans) return true;
            ans = solve(stones,pos+prevstep,prevstep,mp_st,dp);
            if(ans) return true;
            ans = solve(stones,pos+(prevstep+1),prevstep+1,mp_st,dp);
            if(ans) return true;
        }
        dp[{pos,prevstep}] = ans;
        return ans;
    }
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,bool>mpst;
        map<pair<int,int>,bool> dp;
        for(auto st : stones){
            mpst[st] = true;
        }
        
        return solve(stones,0,1,mpst,dp);
    }
};