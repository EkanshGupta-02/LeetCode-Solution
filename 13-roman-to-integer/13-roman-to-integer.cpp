class Solution {
public:
    int romanToInt(string s) {
        int size=s.length();
        int sum=0;
        int flag=0;
        
        for(int i=0;i<size;i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    sum+=4;
                    flag=1;
                }
                else if(s[i+1]=='X'){
                    sum+=9;
                    flag=1;
                }
                else{
                    sum+=1;
                }
            }
            else if(s[i]=='V'){
                sum+=5;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    sum+=40;
                    flag=1;
                }
                else if(s[i+1]=='C'){
                    sum+=90;
                    flag=1;
                }
                else{
                    sum+=10;
                }
            }
            else if(s[i]=='L'){
                sum+=50;
            }
            if(s[i]=='C'){
                if(s[i+1]=='D'){
                    sum+=400;
                    flag=1;
                }
                else if(s[i+1]=='M'){
                    sum+=900;
                    flag=1;
                }
                else{
                    sum+=100;
                }
            }
            else if(s[i]=='D'){
                sum+=500;
            }
            else if(s[i]=='M'){
                sum+=1000;
            }
            if(flag){
                i++;
                flag=0;
            }
        }
        return sum;
    }
};