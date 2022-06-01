class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long temp=target-nums[i]-nums[j];
                int s=j+1;
                int e=n-1;
                while(s<e){
                    if(nums[s]+nums[e]==temp){
                        ans.insert({nums[i],nums[j],nums[s],nums[e]});
                    }
                    if(nums[s]+nums[e]>temp){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
            }
        }
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};