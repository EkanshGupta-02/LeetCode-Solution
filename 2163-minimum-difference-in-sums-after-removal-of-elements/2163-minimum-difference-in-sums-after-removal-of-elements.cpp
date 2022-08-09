#define  lln long long int
class Solution {
    
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<long long int>pq;
        long long int N=nums.size();
        long long int n=N/3;
        
        vector<long long int>part1;
        
        long long int sum1=0;
        for(long long int i=0;i<2*n;i++){
            sum1+=nums[i];
            
            pq.push(nums[i]);
            
            if(pq.size()>n){
                sum1-=pq.top();
                pq.pop();
            }
            
            if(pq.size()==n){
                part1.push_back(sum1);
            }
        }
        
        priority_queue<long long int,vector<long long int>,greater<long long int>>mq;
        
        vector<long long int>part2;
        
        long long int sum2=0;
        
        for(long long int i=3*n-1;i>=n;i--){
            sum2+=nums[i];
            
            mq.push(nums[i]);
            
            if(mq.size()>n){
                sum2-=mq.top();
                mq.pop();
            }
            
            if(mq.size()==n){
                part2.push_back(sum2);
            }
        }
        
        reverse(part2.begin(),part2.end());
        
        
        lln ans=LLONG_MAX;
        
        for(long long int i=0;i<part1.size();i++){
            ans=min(ans,part1[i]-part2[i]);
        }
        
        return ans;
    }
};