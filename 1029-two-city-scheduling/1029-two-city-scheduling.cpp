class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
       int n = costs.size();
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            int diff = costs[i][0]-costs[i][1];
            v.push_back({diff,i});
        }
        
        sort(v.begin(),v.end());
        
        int ans=0;
        
        int cnt=0;
        
        for(auto el:v){
            cnt++;
            if(cnt<=(n/2)){
                ans += costs[el.second][0];
            }
            else{
                ans += costs[el.second][1];
            }
        }
        
        return ans;
    }
};