class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        int presum=0;
        
        for(int i=0;i<nums.size();i++){
            
            int n = nums[i];
            presum+=n;
            
            if(presum%k==0 && i) return true;
            
            if(mp.find(presum%k)!=mp.end()){
                if(mp[presum%k]<i){
                    return true;
                }
            }
            else{
                mp[presum%k] = i+1;
            }
        }
        
        return false;
    }
};