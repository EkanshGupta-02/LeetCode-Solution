class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        
        for(auto n:nums){
            mp[n]++;
        }
        
        vector<int>ans;
        for(auto m:mp){
            if(m.second>floor(n/3)){
                ans.push_back(m.first);
            }
        }
        
        return ans;
    }
};