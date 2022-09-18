class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>duplicate = heights;
        sort(duplicate.begin(),duplicate.end());
        
        int cnt = 0; 
        
        for(int i=0;i<heights.size();i++){
            if(duplicate[i] != heights[i]){
                cnt++;
            }
        }
        
        return cnt;
    }
};