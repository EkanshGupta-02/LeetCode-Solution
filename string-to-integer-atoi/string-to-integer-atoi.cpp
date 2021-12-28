class Solution {
public:
    int myAtoi(string s) {
        int index = -1, n = s.length();
        while (true) {
            index++;
        if (s[index] == '-' || s[index] == '+' || (s[index] >= '0' && s[index] <= '9'))
            break;
        if (s[index] == ' ') {
            continue;
               }
         else
            return 0;
        }
    bool isNeg = s[index] == '-';
        if (s[index] == '+' || s[index] == '-')
            index++;
             while (s[index] == '0') {
                index++;
            }
            long nums = 0;
        while (index < n) {
            if (s[index] >= '0' && s[index] <= '9'){
                if(nums>INT_MAX || nums < INT_MIN){
                    break;
                }
                     nums = nums * 10 + (s[index] - '0');
                        index++;
                }
            else{
                    break;
                }
            }
        if (isNeg == true) {
                nums = -nums;
            }
        if (nums > INT_MAX) {
               return INT_MAX;
         }
        if (nums < INT_MIN){
            return INT_MIN;
                }
    return nums;
    }
};