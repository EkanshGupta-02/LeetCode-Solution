class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>>ans(n,vector<int>(n));
        
        int rs=0;
        int re=n-1,cs=0,ce=n-1;
        int dir=0;
        
        int cnt=1;
        
        while(rs <= re  && cs <= ce){
            if(dir==0){
                for(int i=rs;i<=re;i++){
                    ans[cs][i]=cnt;
                    cnt++;
                }
                
                dir++;
                cs++;
            }
            
            else if(dir==1){
                for(int i=cs;i<=ce;i++){
                    ans[i][re]=cnt;
                    cnt++;
                }
                dir++;
                re--;
            }
            else if(dir==2){
                for(int i=re;i>=rs;i--){
                    ans[ce][i]=cnt;
                    cnt++;
                }
                dir++;
                ce--;
            }
            else if(dir==3){
                 for(int i=ce;i>=cs;i--){
                    ans[i][rs]=cnt;
                    cnt++;
                }
                dir=0;
                rs++;
            }
        }
        
        return ans;
    }
};