class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        priority_queue<int>q;
        
        for(auto n:nums){
            q.push(n);
        }
        
        int sum=0;
        
        while(!q.empty()){
            q.pop();
            sum+=q.top();
            q.pop();
        }
        
        return sum;
    }
};