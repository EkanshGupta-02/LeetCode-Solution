class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        unordered_set<string>vis;
        int ans=0;
        
        int n = bank.size();
        q.push(start);
        vis.insert(start);
        
        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
            string node = q.front();
            q.pop();
            if (node == end) {
                return ans;
            }
            for (char c: "ACGT") {
            for(int i=0;i<node.size();i++){
                string temp = node;
                temp[i] = c;
                if(vis.count(temp)==0 && find(bank.begin(),bank.end(),temp)!= bank.end()){
                  q.push(temp);
                  vis.insert(temp);
                    }
                }
            }
            
            }
            ans++;
        }
        return -1;
    }
};