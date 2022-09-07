class Solution {
private:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>&temp,int node,int n){
        temp.push_back(node);
        
        if(node==n-1){
            ans.push_back(temp);
            return;
        }
        
        for(auto j:graph[node]){
            dfs(graph, ans,temp, j, n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      int n = graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        
        dfs(graph,ans,temp,0,n);
        
        return ans;
    }
};