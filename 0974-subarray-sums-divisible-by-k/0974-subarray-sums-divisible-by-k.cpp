class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          int n = nums.size();
        int count = 0 ;
     
        unordered_map<int , int> prevSum;
           prevSum[0] =1;
        int sum = 0;
        for(int i=0 ; i < n ; i++){
          sum+=nums[i];
            int rem = sum%k;
            if(rem < 0){
                rem+=k;
            }
            
            if(prevSum.find(rem) != prevSum.end()){
                count+=prevSum[rem];
            }  
              prevSum[rem]++;
        }
        return count;
    }
};