class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>ans;
        
        for(int i=0;i<nums.size();i++){
            ans[nums[i]].push_back(i);
        }
        
        for(auto mp:ans){
            if(mp.second.size()>1){
                for(int i=0;i<mp.second.size();i++){
                    for(int j=i+1;j<mp.second.size();j++){
                      if(abs(mp.second[i]-mp.second[j])<=k){
                          return true;
                      }
                    }
                }
            }
        }
        
        return false;
    }
};