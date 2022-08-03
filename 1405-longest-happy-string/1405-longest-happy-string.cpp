class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        
        string ans="";
        
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            
            int n = ans.length();
            if(ans.length()<2 || ans[n-1]!=top.second || ans[n-2]!=top.second){
                ans+=top.second;
                top.first--;
                if(top.first>0){
                    pq.push({top.first,top.second});
                }
            }
            else if(!pq.empty()){
                auto t=pq.top();
                pq.pop();
                 ans+=t.second;
                t.first--;
                if(t.first>0) pq.push({t.first,t.second});
                pq.push(top);
            }
            else break;
        }
        
        return ans;
    }
};