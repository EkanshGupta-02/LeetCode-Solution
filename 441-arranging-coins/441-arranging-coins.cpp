class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1){
            return 1;
        }
        int k=1;
        int ans=0;
        
        while(n-k>=0){
            ans++;
            n=n-k;
            k++;
        }
        
        return ans;
    }
};