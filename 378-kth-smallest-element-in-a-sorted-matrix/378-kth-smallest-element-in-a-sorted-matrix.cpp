class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int t=row*col;
        
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(matrix[i/col][i%col]);
        }
        
        for(int i=k;i<t;i++){
            if(pq.top()>matrix[i/col][i%col]){
                pq.pop();
                pq.push(matrix[i/col][i%col]);
            }
        }
        
        
        return pq.top();
    }
};
