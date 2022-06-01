class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n=time.size();
        long long cnt=0;
        
        vector<int>remainder(60,0);
        
        for(int i=0;i<n;i++){
            int temp=time[i]%60;
            
            if(temp==0){
                cnt+=remainder[0];
            }
            else{
                cnt+=remainder[60-temp];
            }
            
            remainder[temp]++;
        }
        
        return cnt;
    }
};