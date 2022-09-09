class Solution {
public:
     static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        // cout<<properties[0][0]<<endl;
        int temp = INT_MIN;
        int ans=0;
        for(auto p:properties){
            if(temp>p[1]) ans++;
            else temp=p[1];
        }
        return ans;
    }
};