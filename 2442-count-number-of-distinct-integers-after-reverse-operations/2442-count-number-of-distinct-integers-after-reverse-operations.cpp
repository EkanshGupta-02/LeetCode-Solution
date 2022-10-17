class Solution {
public:
    int reverse(int n){
        int newnum=0;
        
        while(n!=0){
            newnum = newnum*10 + n%10;
            n=n/10;
        }
        
        return newnum;
    }
    int countDistinctIntegers(vector<int>& nums) {
       unordered_set<int>st(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
                int newn = reverse(nums[i]);
                if(st.find(newn)==st.end())
                    st.insert(newn);
        }
        
        return st.size();
    }
};