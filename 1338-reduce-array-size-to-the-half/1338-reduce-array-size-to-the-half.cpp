class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        
        for(auto a:arr){
            mp[a]++;
        }
        
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        
        int cnt=0;
        int size=0;
        int n=arr.size();
        
        while(size<(n/2)){
            size += pq.top().first;
            pq.pop();
            cnt++;
        }
        
        return cnt;
    }
};