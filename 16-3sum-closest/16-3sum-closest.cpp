class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
       int n=nums.size();
        int mini=INT_MAX;
        int sum=0;
        int i=0;
        while(i<n-2){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                int tempdiff= abs(target-temp);
                
                if(tempdiff<mini){
                    mini=tempdiff;
                    sum=temp;
                }
                
                
                if(temp > target)k--;
                else if(temp < target) j++;
                else return target;
            }
            
            i++;
        }
        
        return sum;
    }
};