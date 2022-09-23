class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod=1e9+7;
    string s1="";
    
    for(int i=n;i>=1;i--)
    {
        int num=i;
        while(num!=0)
        {
            s1.push_back((num%2)+'0');
            num=num/2;
        }
    }
    
    reverse(s1.begin(),s1.end());
    long long sum=0;
    long long k=1;
    for(int i=s1.length()-1;i>=0;i--)
    {
         sum= (sum + (k*(s1[i]-'0'))%mod ) %mod;
         k=(k*2)%mod;
    }
    
    return sum;
    }
};