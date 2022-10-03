class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        
        int n=colors.size(),cost=0,i=0;
        while(i<n-1)
        {
            if(colors[i]==colors[i+1])
            {
                int mini=INT_MIN;
                while(colors[i]==colors[i+1])
                {
                    mini=max(mini,time[i]);
                    cost+=time[i];
                    i++;
                }
                mini=max(mini,time[i]);
                cost+=time[i];
                cost-=mini;
            }
            else
            {
                i++;
            }
        }  
        return cost;
    }
};