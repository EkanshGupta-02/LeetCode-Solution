class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
     //   for n=0 set bits are 0 
        ans[0]=0;
        
    //    for every i it has 1 more set bit than i/2 if i is odd and equall otherwise.
        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+i%2;
        }
        
        return ans;
    }
};