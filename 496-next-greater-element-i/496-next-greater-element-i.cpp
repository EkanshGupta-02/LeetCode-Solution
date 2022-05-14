class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&nums1, vector<int>&nums2) {
        int x = -1;
        vector<int>ans;
        int m=nums1.size();
        int n=nums2.size();
        stack<int>s1,s2;
        
        for(int i=0;i<n;i++){
            s2.push(nums2[i]);
        }
        
        for(int i=0;i<m;i++){
            while(nums1[i]!=s2.top()){
                if(s2.top()>nums1[i]){
                    x=s2.top();
                }
                if(nums1[i]!=s2.top()){
                    int p=s2.top();
                    s2.pop();
                    s1.push(p);
                }
            }
            
            if(x<=nums1[i]){
                ans.push_back(-1);
            }
            else{
                ans.push_back(x);
            }
            x=-1;
            while(!s1.empty()){
                int q=s1.top();
                s1.pop();
                s2.push(q);
            }
        }
        
        return ans;
    }
};