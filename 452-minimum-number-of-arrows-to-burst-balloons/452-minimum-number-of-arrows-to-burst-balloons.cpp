class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto p:points){
            pq.push(make_pair(p[0],p[1]));
        }
        
        int cnt = 0;
        
        while(pq.size()!=1){
            pair<int,int> top1 = pq.top();
            pq.pop();
            pair<int,int> top2 = pq.top();
            pq.pop();
                
            if(top1.second>=top2.first){
                pair<int,int>p;
                p.first = top2.first;
                p.second = min(top1.second,top2.second);
                
                pq.push(p);
            }
            else{
                cnt++;
                pq.push(top2);
            }
        }
        
        return cnt+1;
    }
};