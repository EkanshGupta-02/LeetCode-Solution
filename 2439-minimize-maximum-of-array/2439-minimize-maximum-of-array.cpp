class Solution {
public:
    int check(vector<int>&nums,int mid){
        int n = nums.size();
        long long int cnt=0;
        bool ans = true;
        
        for(int i=0;i<n;i++){
            cnt += (nums[i]-mid);
            if(cnt>0){
                ans = false;
                break;
            }
        }
        
        return ans;
    }
    int minimizeArrayValue(vector<int>& nums) {
       vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        int s = temp[0];
        int n = nums.size();
        int e = temp[n-1];
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(nums,mid)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};