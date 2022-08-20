class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      if(stations.size()==0){
          return startFuel>=target?0:-1;
      }
        int cnt=0;
        int currcap=startFuel;
        int i=0;
        priority_queue<int>pq;
        
        while(target>currcap){
            cnt++;
            while(i<stations.size() && stations[i][0]<=currcap){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) break;
            
            currcap+=pq.top();
            pq.pop();
        }
        
        if(currcap>=target){
            return cnt;
        }
        return -1;
    }
};