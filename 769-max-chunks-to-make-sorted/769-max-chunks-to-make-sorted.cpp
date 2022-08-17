class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt=0;
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            
            if(pq.top()==i){
                while(!pq.empty()) pq.pop();
                
                cnt++;
            }
        }
        
        return cnt;
    }
};