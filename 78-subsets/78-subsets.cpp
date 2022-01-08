class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int>> res;
        
        for(int i=0;i<pow(2,n);i++)
        {
            vector<int> seq;
            for(int bit=0;bit<n;bit++)
            {
                if(i & (1<<bit))
                    seq.push_back(nums[bit]);
            }
            
            res.push_back(seq);
        }
        return res;
    }
};