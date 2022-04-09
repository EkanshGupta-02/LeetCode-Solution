class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        unordered_map<int,int>:: iterator it=mp.begin();
        priority_queue<pair<int,int>> p;
        
        for(;it!=mp.end();it++){
            p.push(make_pair(it->second,it->first));
        }
        
        int temp=0;
        vector<int> ans;
        
        while(temp<k){
            ans.push_back(p.top().second);
            p.pop();
            temp++;
        }
        
        
        return ans;
        
        
    }
};