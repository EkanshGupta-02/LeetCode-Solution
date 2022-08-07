/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int solve(unordered_map<int,Employee*>&mp,int eid){
        int ans = mp[eid]->importance;
        
        for(auto it:mp[eid]->subordinates){
            ans += solve(mp,it);
        }
        
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        for(auto e:employees){
            mp[e->id]=e;
        }
        int ans = solve(mp,id);
        return ans;
    }
};