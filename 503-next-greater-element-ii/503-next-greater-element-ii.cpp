class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        st.push(INT_MIN);
        
        vector<int>ans(nums.size());
        
        for(int i = nums.size()-1 ;i>=0;i--){
            st.push(nums[i]);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            int curr  = nums[i];
            
            while(st.top()!=INT_MIN && curr>=st.top()){
                st.pop();
            }
            
            ans[i] = st.top()==INT_MIN?-1:st.top();
            st.push(curr);
        }
        
        return ans;
    }
};