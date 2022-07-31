class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int netgasrequired = 0;
        
        for(int i=0;i<gas.size();i++){
            netgasrequired += (gas[i]-cost[i]); 
        }
        
        if(netgasrequired<0){
            return -1;
        }
        
        int gasavailable = 0,startindex=0;
        for(int i=0;i<gas.size();i++){
              
            gasavailable += gas[i]-cost[i];
            
            if(gasavailable<0){
                startindex = i+1;
                
                gasavailable=0;
            }
        }
        
        return startindex;
    }
};