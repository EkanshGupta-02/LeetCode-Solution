class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,vector<int>>mp;
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            mp[sum%k].push_back(i);
        }
        
        for(auto i:mp){
            if(i.first==0 && i.second[i.second.size()-1]>=1) return true;
            if(i.second.size()>=2 && (i.second[i.second.size()-1]-i.second[0])>=2) return true;
        }
        
        return false;
    }
};