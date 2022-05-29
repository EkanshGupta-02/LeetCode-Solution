class Solution {
public:
   int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>bit(n);
       for(int i=0;i<n;i++){
           int tbit=0;
           for(int j=0;j<words[i].size();j++){
               tbit |= 1<<(words[i][j]-'a');
           }
           bit[i]=tbit;
       }
       
       int maxi=0;
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               if((bit[i]&bit[j])==0){
                   int t=words[i].length()*words[j].length();
                   maxi = max(maxi,t);
               }
           }
       }
       
       return maxi;
    }
};