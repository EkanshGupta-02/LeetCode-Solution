class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
        vector<int>ans;
        
        for(auto m:mp){
            if(m.second>1){
                ans.push_back(m.first);
            }
        }
        
        return ans;
    }
};