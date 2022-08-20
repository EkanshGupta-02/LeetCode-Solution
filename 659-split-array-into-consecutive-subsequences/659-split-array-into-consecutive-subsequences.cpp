class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
        
        unordered_map<int,int>need;
        
        for(int n:nums){
            if(mp[n]==0) continue;
            
            if(need[n]>0){
                mp[n]--;
                need[n]--;
                
                need[n+1]++;
            }
            
            else if(mp[n]>0 && mp[n+1]>0 && mp[n+2]>0){
                mp[n]--;
                mp[n+1]--;
                mp[n+2]--;
                
                need[n+3]++;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};