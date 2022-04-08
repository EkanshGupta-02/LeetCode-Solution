class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> a;
    int temp;
    
    
    KthLargest(int k, vector<int>& nums) {
        
        temp=k;
        
        for(int i=0;i<nums.size();i++){
            
            a.push(nums[i]);
            
            if(a.size()>temp){
                a.pop();
            }
        }
        
    }
    
    int add(int val) {
        
        a.push(val);
        
        if(a.size()>temp){
            a.pop();
        }
        
        return a.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */