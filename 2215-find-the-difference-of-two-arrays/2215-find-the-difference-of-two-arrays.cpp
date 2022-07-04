class Solution {
public:
    vector<int>distinct(vector<int>&nums1,vector<int>&nums2){
        unordered_map<int,int>mp;
        
        int i=nums1.size()-1;
        while(i>=0){
            mp[nums1[i]]++;
            i--;
        }
        vector<int>ans;
        int j=nums2.size()-1;
        
        while(j>=0){
            if(mp[nums2[j]]==0){
                ans.push_back(nums2[j]);
                mp[nums2[j]]++;
            }
            j--;
        }
        
        return ans;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        ans[0]=distinct(nums2,nums1);
        ans[1]=distinct(nums1,nums2);
        
        return ans;
    }
};