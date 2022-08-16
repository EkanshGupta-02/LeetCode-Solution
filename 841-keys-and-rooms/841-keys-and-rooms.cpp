class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        
        visited[0]=1;
        
        stack<int>key;
        key.push(0);
        
        while(!key.empty()){
            int tempkey = key.top();
            key.pop();
            
            for(auto it:rooms[tempkey]){
                if(!visited[it]){
                    visited[it]=1;
                    key.push(it);
                }
            }
        }
        
        
        for(auto v:visited){
            if(v==0) return false;
        }
        
        return true;
    }
};