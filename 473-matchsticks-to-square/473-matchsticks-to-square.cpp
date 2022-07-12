class Solution {
public:
    int side1,side2,side3,side4;
    bool solve(vector<int>&matchsticks,int index){
        if(index==matchsticks.size()){
            if(side1==0 && side2==0 && side3==0 && side4==0) return true;
            return false;
        }
        
        if(matchsticks[index]<=side1){
            side1-=matchsticks[index];
            if(solve(matchsticks,index+1)) return true;
            side1+=matchsticks[index];
        }
        
        if(matchsticks[index]<=side2){
            side2-=matchsticks[index];
            if(solve(matchsticks,index+1)) return true;
            side2+=matchsticks[index];
        }
        
        if(matchsticks[index]<=side3){
            side3-=matchsticks[index];
            if(solve(matchsticks,index+1)) return true;
            side3+=matchsticks[index];
        }
        
        if(matchsticks[index]<=side4){
            side4-=matchsticks[index];
            if(solve(matchsticks,index+1)) return true;
            side4+=matchsticks[index];
        }
        
        return false;
    } 
    bool makesquare(vector<int>& matchsticks) {
       if(matchsticks.size()<4) return false;
        
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0){
            return false;
        }
        
        side1=side2=side3=side4=sum/4;
        
        sort(matchsticks.rbegin(),matchsticks.rend());
        return solve(matchsticks,0);
    }
};