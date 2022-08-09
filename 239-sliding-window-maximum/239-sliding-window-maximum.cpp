class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
        if(k==1) return nums;
        int n=nums.size();
        
        vector<int>ans;
        deque<int>dq;
        
        int j=0;
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(j > dq.front()) dq.pop_front();
            
            if(i+1>=k){
                ans.push_back(nums[dq.front()]);
                j++;
            }
        }
        
        return ans;
        
    }
};