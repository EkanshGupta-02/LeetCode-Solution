class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<long long,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<2;j++){
                sum+=pow(points[i][j],2);
            }
            if(pq.size()<k){
                pq.push({sum,{points[i][0],points[i][1]}});
            }
            else if(pq.top().first>sum){
                pq.pop();
                pq.push({sum,{points[i][0],points[i][1]}});
            }
        }
        
        vector<vector<int>>ans;
        
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};