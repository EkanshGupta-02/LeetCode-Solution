class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0){
        int t=x%10;
            x=x/10;
            if(rev > INT_MAX/10) return 0;
            if(rev <INT_MIN/10) return 0;
            rev=rev * 10 + t;
        }
        return rev;
    }
};