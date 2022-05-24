class Solution {
    int hapnum(int n){
        int ans=0;
        while(n!=0){
            int t=n%10;
            n=n/10;
            ans+=pow(t,2);
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int p=n;
        int q=hapnum(n);
        
        while(q!=1 && p!=q){
            p=hapnum(p);
            q=hapnum(hapnum(q));
        }
        
       return q==1; 
    }
};