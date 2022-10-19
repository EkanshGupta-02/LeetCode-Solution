class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum=0;
        if(n%2==0){
            int diff = (nums[(n-1)/2] + nums[n/2])/2;
            for(int i=0;i<n;i++){
                sum += abs(nums[i]-diff);
            }
            return sum;
        }
        else{
            int diff = nums[n/2];
            for(int i=0;i<n;i++){
                sum += abs(nums[i]-diff);
            }
            return sum;
        }
    }
};