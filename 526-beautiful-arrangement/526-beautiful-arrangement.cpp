class Solution {
    void solve(vector<int>&nums,int& cnt,int index){
        if(index==nums.size()){
            cnt++;
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            if((nums[index]%(index+1)==0) || ((index+1)%nums[index]==0)){
                solve(nums,cnt,index+1);
            }
            swap(nums[i],nums[index]);
        }
    }
public:
    int countArrangement(int n) {
        int cnt = 0;
        vector<int>nums(n);
        for(int i=1;i<=n;i++){
            nums[i-1] = i;
        }
        solve(nums,cnt,0);
        return cnt;
    }
};