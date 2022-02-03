class Solution {
public:
    long long square(int n){
        
        return n*n;
        
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            nums[i]=square(nums[i]);
        }
        
        sort(nums.begin(),nums.end());
        
        return nums;
    }
};