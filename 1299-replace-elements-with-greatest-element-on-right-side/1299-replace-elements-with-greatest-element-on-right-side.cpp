class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxelement=-1;
        int temp;
        for(int i=arr.size()-1;i>=0;i--){
            temp = arr[i];
            arr[i]=maxelement;
            maxelement=max(temp,maxelement);
        }
        
        return arr;
    }
};