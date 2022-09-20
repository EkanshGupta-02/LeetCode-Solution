class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long>ugly={1};
        vector<long long>index(primes.size(),0);
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        
        for(int i=0;i<primes.size();i++){
            pq.push({primes[i],i});
        }
        
        while(ugly.size()<n){
            pair<long long,int> top  = pq.top();
            pq.pop();
            
            if(top.first != ugly.back()) ugly.push_back(top.first);
            
            index[top.second]++;
            
             pq.push({ugly[index[top.second]] * primes[top.second],top.second});
        }
        
        return ugly.back();
    }
};