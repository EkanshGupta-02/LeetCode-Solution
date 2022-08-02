class Solution {
public:
    bool isvalid(vector<int>&weights,int days,int mid){
        int daycount=1;
        int totalweight=0;
        
        for(int i=0;i<weights.size();i++){
            if(totalweight+weights[i] <= mid){
                totalweight+=weights[i];
            }
            else{
                daycount++;
                totalweight=0;
                if(daycount > days || weights[i] > mid){
                    return false;
                }
                totalweight+=weights[i];
            }
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        long long int totalweight=0;
        
        for(int i=0;i<weights.size();i++){
            totalweight+=weights[i];
        }
        
        long long int end=totalweight;
        int ans=-1;
        int mid=start + (end - start)/2;
        
        while(start<=end){
            if(isvalid(weights,days,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            
            mid = start + (end-start)/2;
        }
        
        return ans;
    }
};