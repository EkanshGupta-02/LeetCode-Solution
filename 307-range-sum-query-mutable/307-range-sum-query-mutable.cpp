class NumArray {
public:
    vector<int>ans;
    int sum=0;
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum -= ans[index];
        ans[index]=val;
        sum += val;
    }
    
    int sumRange(int left, int right) {
        
        int res=sum;
        
        for(int i=0;i<left;i++){
            res-=ans[i];
        }
        
        for(int i=right+1;i<ans.size();i++){
            res-=ans[i];
        }
        
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */