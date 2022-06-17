class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n=digits.size();
        int carry=0;
        int i=n-1;
        
        if(digits.size()==1){
            digits[i]+=1;
            if(digits[i]>9){
                carry=digits[i]/10;
                digits[i]=digits[i]%10;
                digits.insert(digits.begin(),carry);
          }   
           return digits;
        }
        
        do{
            digits[i]=digits[i]+1;
            if(digits[i]>9){
                carry=digits[i]/10;
                digits[i]=digits[i]%10;
                i--;
            }else{
                carry=0;
            }            
        }while(carry!=0 && i>=0);
        
        if(carry){
            digits.insert(digits.begin(),carry);
        }
        
        return digits;
    }
};