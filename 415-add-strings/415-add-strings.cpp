class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
         int i=n-1;
        int j=m-1;
        int carry=0;
        int sum=0;
        string str="";
        
        while(i>=0 || j>=0 || carry==1){
            sum=carry;
            if(i>=0){
                sum += num1[i]-'0';
                i--;
            }
            if(j>=0){
                sum += num2[j]-'0';
                j--;
            }
            carry=sum/10;
            sum=sum%10;
            str+=to_string(sum);
        }
        
        reverse(str.begin(),str.end());
        
        return str;
    }
};