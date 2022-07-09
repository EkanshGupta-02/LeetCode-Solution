class Solution {
public:
    int lastRemaining(int n) {
        bool dir=true;
        int steps=1;
        int ans=1;
        
        while(n>1){
            if(dir){
                ans+=steps;
            }
            else{
                if(n%2!=0){
                    ans+=steps;
                }
            }
            
            n=n/2;
            dir=!dir;
            steps*=2;
        }
        
        return ans;
    }
};