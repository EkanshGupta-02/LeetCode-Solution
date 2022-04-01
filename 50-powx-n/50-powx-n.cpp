class Solution {
public:
    double myPow(double x, int n) {
  
        
        long newn=n;
        
        double ans=1.0;
        
        if(n<0){
            newn=-1.0*n;
        }
        
        while(newn>0){
            
            if(newn%2==0){
                x*=x;
                newn=newn/2;
            }
            else{
                ans*=x;
                newn=newn-1;
            }
        }
        
        if(n<0){
            ans=1.0/ans;
        }
        
        return ans;
    }
};