class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>mp;        
        int n1=nums1.size()-1;
        int n2=nums2.size()-1;
        
        vector<int>ans;
        
    while(n1>=0){
        mp[nums1[n1]]++;
        n1--;
    }
    
    while(n2>=0){
        if(mp[nums2[n2]]>0){
            ans.push_back(nums2[n2]);
            mp[nums2[n2]]--;
        }
        n2--;
    }
    
    return ans;
    }
};