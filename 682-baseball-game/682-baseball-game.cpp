class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(ops[i]=="+"){
                ans.push_back((ans[ans.size()-1]+ans[ans.size()-2]));
            }
            else if(ops[i]=="D"){
                ans.push_back(ans[ans.size()-1]*2);
            }
            else if(ops[i]=="C"){
                ans.pop_back();
            }
            else{
                int temp=stoi(ops[i]);
                ans.push_back(temp);
            }
        }
        
        int cnt=0;
        for(int i=0;i<ans.size();i++){
            cnt+=ans[i];            
        }
        
        return cnt;
    }
};