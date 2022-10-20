class Solution {
    int solve(int num,int sum){
        if(num==1){
            return 1;
        }
        if(num<0){
            return 0;
        }
        int nottaken = solve(num-1,sum);
        
        int taken = 0;
        if(sum>=num){ 
            taken = num*solve(num,sum-num);
        }
        
        return max(taken,nottaken);
    }
public:
    int integerBreak(int n) {
        return solve(n-1,n);      
    }
};