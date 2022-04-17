class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans={{1},{1,1}};
        
        if(rowIndex==0){
            return {{1}};
        }
        
        for(int i=2;i<=rowIndex;i++){
            vector<int>temp(i+1);
            for(int j=0;j<=i;j++){
                
                if(j==0 || j==i){
                    temp[j]=1;
                }
                else
                 temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            
            ans.push_back(temp);
        }
        
        vector<int>res;
        
        for(int i=0;i<ans[rowIndex].size();i++){
            res.push_back(ans[rowIndex][i]);
        }
        
        return res;
    }
};