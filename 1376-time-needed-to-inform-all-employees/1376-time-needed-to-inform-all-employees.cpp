class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<n;i++){
            adj[manager[i]].push_back(i);
        }
        
        int maxi=INT_MIN;
        queue<pair<int,int>>q;
        q.push({headID,0});
        
        while(!q.empty()){
            for(int i=0;i<q.size();i++){
            pair<int,int>front = q.front();
            q.pop();
            int head = front.first;
            int time = front.second;
            
            maxi = max(maxi,time + informTime[head]);
            
            for(auto it:adj[head]){
                q.push({it,time + informTime[head]});
            }     
        }
    }
        
        return maxi;
    }
};