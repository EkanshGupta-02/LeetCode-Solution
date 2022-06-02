class Solution {
public:
    void solve(string& tiles,string& output,set<string>& res,map<int,bool> flag){
//         to check for each character in string
        for(int i=0;i<tiles.length();i++){
            // to track indexes
            if(flag[i]==0){
                char ch=tiles[i];
                output.push_back(ch);
           // to mark index visited
                flag[i]=1;
                
                res.insert(output);
                
                solve(tiles,output,res,flag);
                
          // mark visited index unvisited(i.e backtracking).
                output.pop_back();
                flag[i]=0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        string output="";
        
        set<string>result;
        
        map<int,bool>flag;
        
        solve(tiles,output,result,flag);
        
        return result.size();
    }
};