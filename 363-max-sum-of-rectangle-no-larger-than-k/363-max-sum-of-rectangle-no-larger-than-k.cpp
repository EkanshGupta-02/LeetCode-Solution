class Solution {
private:
    int find_max(vector<int>& arr, int k)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        int curr_sum = 0;
        
        
        set<int> s; 
        
        s.insert(0);
        
        for(int i = 0; i < n; i++)
        {  
            curr_sum += arr[i];
            auto it = s.lower_bound(curr_sum - k);
            if(it != s.end())
            {
                maxi = max(maxi, curr_sum - *it);
            }
            s.insert(curr_sum);
        }
        return maxi;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxi =  INT_MIN;
        
        for(int sr=0;sr<m;sr++){
            vector<int>col(n,0);
            
            for(int er=sr;er<m;er++){
                for(int j =0;j<n;j++){
                    col[j] += matrix[er][j];
                }
                
                int currmax = find_max(col,k);
                
                maxi = max(maxi,currmax);
            }
        }
        
        return maxi;
    }
};