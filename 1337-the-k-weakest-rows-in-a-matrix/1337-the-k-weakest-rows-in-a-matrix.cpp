class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>sumrow;
        int row=mat.size();
        int col=mat[0].size();
        
        for(int i=0;i<row;i++){
            int sum=0;
            for(int j=0;j<col;j++){
                sum+=mat[i][j];
            }
            sumrow.push_back({sum,i});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<sumrow.size();i++){
            pq.push(sumrow[i]);
        }
        
        vector<int>ans;
        for(int i=0;i<k;i++){
            pair<int,int>temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};