class Solution {
public:
    int maxArea(vector<int>& height) {
        int p=0;
        int q=height.size()-1;
          int maxa=0;      
        while(p<q){
        int t=min(height[p],height[q]);
            int area=t*(q-p);
            maxa=max(maxa,area);
            if(height[p]<=height[q]) p++;
            else q--;
        }
        
        return maxa;
    }
};