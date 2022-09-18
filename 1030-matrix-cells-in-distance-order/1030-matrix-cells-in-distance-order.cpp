class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>temp;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                temp.push_back({i,j,abs(i-rCenter) + abs(j-cCenter)});
            }
        }
        
        vector<vector<int>>ans;
        sort(temp.begin(),temp.end(),cmp);
        
        for(int i=0;i<temp.size();i++){
            vector<int>it;
            it.push_back(temp[i][0]);
            it.push_back(temp[i][1]);
            ans.push_back(it);
        }
        
        return ans;
    }
};