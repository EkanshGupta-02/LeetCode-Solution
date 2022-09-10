class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
         set<int>s;
        map<int,int>mp;
        vector<int>ans(rains.size(),-1);
        for(int i=0;i<rains.size();i++){
            if(rains[i]!=0){
                ans[i]=-1;
                if(mp.count(rains[i])){
                    if(s.empty()){
                        return vector<int>{};
                    }
                    else{
                        int left=mp[rains[i]];
                        auto it=s.lower_bound(left);
                        if(it==s.end()){
                            return vector<int>{};
                        }
                        int temp=*it;
                            s.erase(it);
                        ans[temp]=rains[i];
                        mp[rains[i]]=i;
                        
                    }
                
                }
                else{
                    mp[rains[i]]=i;
                }
            }
            else{
               s.insert(i);
            }
        }
        int cut=(mp.size()>0)?mp.begin()->first:1;
        while(!s.empty()){
            int temp=*s.begin();
          s.erase(*s.begin());
            ans[temp]=cut;
        }
        return ans;
        
  }
};