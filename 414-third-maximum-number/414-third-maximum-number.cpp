class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return nums[0]>=nums[1]?nums[0]:nums[1];
        }
        sort(nums.begin(),nums.end());
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        
        vector<int>ans(st.begin(),st.end());
        
        if(ans.size()>2) return ans[ans.size()-3];
        else return ans[ans.size()-1];
    }
};