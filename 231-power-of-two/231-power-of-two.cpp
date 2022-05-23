class Solution {
public:
    bool isPowerOfTwo(long long n) {
      if((n && !(n & n-1))){
          return true;
      }
        return false;
    }
};