class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        
        priority_queue<int> a;
        
        for(int i=0;i<stones.size();i++){
            a.push(stones[i]);
        }
        
        while(a.size()>1){
            
            int a1=a.top();
            a.pop();
            int b=a.top();
            a.pop();
            if(a1!=b){
                int c=a1-b;
                
                a.push(c);
            }
        }
        
        return a.empty()?0:a.top();
    }
};