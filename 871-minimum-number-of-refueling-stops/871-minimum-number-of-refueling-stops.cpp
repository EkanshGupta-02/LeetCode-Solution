class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size()==0){
            return startFuel>=target?0:-1;
        }
        priority_queue<int>pq;
        int statcnt=0;
        int currcap=startFuel;
        int i=0;
        
        
        while(target>currcap){
            statcnt++;
            while(i<stations.size() && stations[i][0]<=currcap){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) break;
            
            currcap+=pq.top();
            pq.pop();
        }
        
        if(currcap>=target) return statcnt;
        else return -1;
    }
};