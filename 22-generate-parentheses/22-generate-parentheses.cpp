class Solution {
public:
    
    void solve(int curopen,int curclose,int remopen,int remclose,vector<string>&res,string output){
        if(remopen==0 && remclose==0){
             res.push_back(output);
            return;
        }
        
        if(remopen>0){
            output.push_back('(');
            solve(curopen+1,curclose,remopen-1,remclose,res,output);
            
            output.pop_back();
        }
        
        if(remclose>0 && curopen>curclose){
            output.push_back(')');
            solve(curopen,curclose+1,remopen,remclose-1,res,output);
            
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="(";
        
        int curropen=1;
        int currclose=0;
        int remopen=n-1;
        int remclose=n;
        
        solve(curropen,currclose,remopen,remclose,ans,output);
            
        return ans;
    }
};