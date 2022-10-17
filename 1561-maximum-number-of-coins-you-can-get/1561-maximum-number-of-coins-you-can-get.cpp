class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<int>pq;
        int n = piles.size();
        
        for(auto p:piles){
            pq.push(p);
        }
        int sum=0;
        while(pq.size()>(n/3)){
            pq.pop();
            int top = pq.top();
            pq.pop();
            sum+=top;
        }
        
        return sum;
    }
};