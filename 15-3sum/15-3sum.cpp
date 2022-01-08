class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int n = nums.size()-1;
        set<vector<int>> ans;
    int r,l;
    for(int i=0; i<n-1; i++){

            l= i+1;
            r= n;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum==0){
                    ans.insert({nums[i], nums[l] , nums[r]});
                    l++;
                    r--;
                }
                else if (sum>0){
                    r--;

                }
                else{
                    l++;
                }

            }

        }
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};