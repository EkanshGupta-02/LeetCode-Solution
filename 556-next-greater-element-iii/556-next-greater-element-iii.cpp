class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int m = str.size();
        int i;
        
        for(i=m-2;i>=0;i--){
            if(str[i]<str[i+1]) break;
        }
        
        if(i==-1) return -1;
        
        int j;
        for(j=m-1;j>i;j--){
            if(str[j]>str[i]) break;
        }
        swap(str[i],str[j]);
        reverse(str.begin()+i+1,str.end());
        
        
        return stol(str)>INT_MAX?-1:stol(str);
    }
};