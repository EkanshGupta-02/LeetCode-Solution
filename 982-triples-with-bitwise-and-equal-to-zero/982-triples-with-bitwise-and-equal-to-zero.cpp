class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,int>mp;
        
        for(auto n1:nums){
            for(auto n2:nums){
                ++mp[n1 & n2];
            }
        }
        
        for(auto n3 : nums){
            for(auto m : mp){
                if((m.first & n3) == 0){
                    cnt += m.second;
                } 
            }
        }
        
        return cnt;
    }
};