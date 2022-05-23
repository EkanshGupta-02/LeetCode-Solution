class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0){
           return false;
       }
        long long rev=0;
        int n=x;
        
        while(n!=0){
            int t=n%10;
            rev=rev*10+t;
            n=n/10;
        }
        
        if(rev==x){
            return true;
        }
        else{
            return false;
        }
    }
};