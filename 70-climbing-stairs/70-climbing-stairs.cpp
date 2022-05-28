class Solution {
public:
  int climbStairs(int n) {
        int n1=1;
      int n2=1;
      
      int curr=0;
      
      for(int i=2;i<n+1;i++){
          curr=n1+n2;
          n2=n1;
          n1=curr;
      }
      
      return n1;
    }
};