class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       vector<int> p(2051,0);
        int res=0;
        for(auto l:logs){
            p[l[0]]++;
            p[l[1]]--;
        }
        for(int i=1950;i<=2050;i++)
        {
            p[i]+=p[i-1];
            res=p[i]>p[res]?i:res;
        }
        return res;
    }
};