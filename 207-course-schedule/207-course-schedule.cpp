class Solution {
public:
    bool checkcycle(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>& visited,
                         unordered_map<int,bool>& dfsvisited){
        visited[node]=true;
        dfsvisited[node]=true;
        
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(checkcycle(neighbour,adj,visited,dfsvisited)) return true;
            }
            else if(dfsvisited[neighbour]){
                return true;
            }
        }
        
        dfsvisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsvisited;
        unordered_map<int,list<int>>adj;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool hascycle = checkcycle(i,adj,visited,dfsvisited);
                if(hascycle){
                    return false;
                }
            }
        }
        
        return true;
    }
};