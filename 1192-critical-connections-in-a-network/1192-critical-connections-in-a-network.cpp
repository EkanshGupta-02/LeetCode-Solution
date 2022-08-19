class Solution {
private:
    void dfs(int node,int parent,int& timer,vector<int>&disc,vector<int>&low,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis,vector<vector<int>>&result){
        vis[node]=1;
        disc[node]=low[node]=timer++;
        
        for(auto nbr:adj[node]){
            if(nbr == parent) continue;
            
            if(!vis[nbr]){
                dfs(nbr,node,timer,disc,low,adj,vis,result);
                low[node]=min(low[nbr],low[node]);
                
                if(low[nbr]>disc[node]){
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else{
                low[node] = min(disc[nbr],low[node]); 
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        unordered_map<int,bool>vis;
        int timer=0;
        int parent=-1;
        vector<vector<int>>result;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,parent,timer,disc,low,adj,vis,result);
            }
        }
        
        return result;
    }
};