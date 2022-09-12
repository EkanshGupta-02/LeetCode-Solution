class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start=0, end= tokens.size()-1;
        int cscore=0; int ans = 0;
        while(start<=end)
        {
          if(power >= tokens[start]) {  
                power -= tokens[start];
                cscore++;
                ans=max(ans, cscore);
                start++;
          }
            
            else if(cscore>=1){
                power += tokens[end];
                cscore --;
                end--;
            }
            else
                break; 
        }
        
        return ans;
        
    }
};