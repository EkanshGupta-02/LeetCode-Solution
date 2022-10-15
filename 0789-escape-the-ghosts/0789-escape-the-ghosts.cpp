class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]-0) + abs(target[1]-0);
        
        for(int i=0;i<ghosts.size();i++){
            int ghostdist = abs(target[0]-ghosts[i][0]) + abs(target[1]-ghosts[i][1]);
            if(ghostdist<=dist){
                return false;
            }
        }
        
        return true;
    }
};