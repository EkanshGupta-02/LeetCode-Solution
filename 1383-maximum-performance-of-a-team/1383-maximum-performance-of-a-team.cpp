const int mod = (int)1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        vector<pair<int,int>>ans;
    
        for(int i=0;i<n;i++){
            ans.push_back({efficiency[i],speed[i]});        
        }
        
        sort(ans.rbegin(),ans.rend());
        
        long long int totspeed=0;
        long long int res=INT_MIN;
        
        for(int i=0;i<n;i++){
            int eff = ans[i].first;
            int speed = ans[i].second;
            
            if(pq.size()==k){
                totspeed-=pq.top();
                pq.pop();
            }
            
            pq.push(speed);
            
            totspeed = (totspeed + speed);
            
            long long int prod = (totspeed * eff);
            res = max(res,prod);
        }
        return res%mod;
    }
};