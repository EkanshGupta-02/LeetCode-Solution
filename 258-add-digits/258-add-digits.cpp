class Solution {
public:
    int digisum(int n){
        int sum=0;
        
        while(n!=0){
            sum+=n%10;
            n=n/10;
        }
        
        return sum;
    }
    int addDigits(int num) {
        if(num==0){
            return 0;
        }
        int n=num;
        
        while(n>9){
            n=digisum(n);
        }
        
        return n;
    }
};