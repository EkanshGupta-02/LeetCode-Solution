class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        
        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            
            int secondtop  = pq.top();
            pq.pop();
            
            top--;
            secondtop--;
            if(top) pq.push(top);
            if(secondtop) pq.push(secondtop);
            
            cnt++;
        }
        
        return cnt;
    }
};