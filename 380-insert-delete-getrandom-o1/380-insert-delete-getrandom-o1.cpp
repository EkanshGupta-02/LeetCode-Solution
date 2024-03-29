class RandomizedSet {
public:
    vector<int>ans;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        
        else{
            ans.push_back(val);
            mp[val] = ans.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int last_element = ans.back();
            ans[mp[val]] = ans.back();
            ans.pop_back();
            mp[last_element]=mp[val];
            mp.erase(val);
            
            return true;
        }
    }
    
    int getRandom() {
        return ans[rand()%ans.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */