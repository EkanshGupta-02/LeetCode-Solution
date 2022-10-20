class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
          int res = 0, currBatch;
        sort(boxTypes.begin(), boxTypes.end(),cmp);
        for (auto &el: boxTypes) {
            currBatch = min(el[0], truckSize);
            truckSize -= currBatch;
            res += currBatch * el[1];
            if (!truckSize) break;
        }
        return res;
    }
};