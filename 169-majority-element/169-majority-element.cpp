class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_index=0, cnt=1, n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[maj_index])   cnt++;
            else    cnt--;
            
            if(cnt==0)  maj_index=i, cnt=1;
        }
        return nums[maj_index];
        }
};