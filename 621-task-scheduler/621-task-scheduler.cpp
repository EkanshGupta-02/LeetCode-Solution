class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        
        priority_queue<int>pq;
        
        unordered_map<char,int>mp;
        for(auto t:tasks){
            mp[t]++;
        }
        
        for(auto m:mp){
            pq.push(m.second);
        }
        
        queue<pair<int, int>> cooldown;
        int totalTime = 0;
        
        while(!pq.empty() || !cooldown.empty()){
            if(!cooldown.empty() && cooldown.front().second==totalTime){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            
            if(!pq.empty()) {    
                int task = pq.top(); 
                pq.pop();
                task--;
                if(task != 0) cooldown.push({task, totalTime + n + 1});
            }
            totalTime++;
        }
        
        return totalTime;
    }
};