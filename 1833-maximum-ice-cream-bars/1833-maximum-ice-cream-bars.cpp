class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        
        int i=0;
        
        while(coins>0 && i<costs.size()){
            if(coins>=costs[i]){
                coins-=costs[i];
                cnt++;
            }
            i++;
        }
        
        return cnt;
    }
};