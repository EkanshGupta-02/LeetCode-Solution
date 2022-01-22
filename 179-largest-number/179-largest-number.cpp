class Solution {
public:
      static bool compare(string a, string b){
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            arr.push_back(s);
        }
        sort(arr.begin(), arr.end(), compare);
        string ans = "";
        for(int i=0;i<arr.size();i++){
            ans += arr[i];
        }
        auto it = ans.begin();
        while(*it == '0' && ans.size() > 1)
        {
            ans.erase(it);
        }
        return ans;
    }
};