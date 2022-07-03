class NumArray {
public:
    vector<int>b;
    NumArray(vector<int>& nums) {
        vector<int>a=nums;
        
        b.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            b.push_back(nums[i]+b.back());
        }
    }
    
    int sumRange(int left, int right) {
        return (left>0)?b[right]-b[left-1]:b[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */