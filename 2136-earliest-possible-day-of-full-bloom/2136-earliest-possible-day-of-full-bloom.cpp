class Solution {
public:
   
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int>sortindex(growTime.size());
        
        iota(sortindex.begin(),sortindex.end(),0);
        sort(sortindex.begin(),sortindex.end(),[&](int a,int b){return growTime[a]>growTime[b];});
        
        int ans=0;
        int plantt=0;
        for(auto i:sortindex){
            plantt+=plantTime[i];
            ans = max(ans,plantt + growTime[i]);
        }
        
        return ans;
    }
    //  static bool cmp(int&a,int&b){
    //     return growTime[a]>growTime[b];
    // }
};