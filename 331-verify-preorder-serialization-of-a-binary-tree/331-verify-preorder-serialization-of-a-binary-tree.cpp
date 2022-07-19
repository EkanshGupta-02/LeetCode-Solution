class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream str(preorder);
        vector<string>ans;
        string node;
        while(getline(str,node,',')){
            ans.push_back(node);
        }
//         using logic leafnode=noleaf+1;              
        int count=0;
              
              for(auto i:ans){
                  if(count<0){
                      return false;
                  }
                  
                  if(i=="#"){
                      count--;
                  }
                else{
                    count++;
                }
              }
              
              return (count==-1);
    }
};