class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int temp=0;
        int ans=0;
        for(int i=0;i<k;i++){
            temp+=cardPoints[i];
        }
        
        ans=max(ans,temp);
        
        for(int i=k-1;i>=0;i--){
            temp-=cardPoints[i];
            temp+=cardPoints[n-k+i];
            ans=max(ans,temp);
        }
        
        return ans;
    }
};