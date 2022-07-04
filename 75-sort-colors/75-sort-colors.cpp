class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            else if(nums[i]==1) one++;
            else two++;
        }
        cout<<zero<<' '<<one<<" "<<two;
        for(int i=0;i<n;i++){
            if(zero>0){
                nums[i]=0;
                zero--;
            }
            else if(zero==0 && one!=0){
                nums[i]=1;
                one--;
            }
            else{
                nums[i]=2;
                two--;
            }
        }
    }
};