class CombinationIterator {
public:
    vector<bool>bits;
    string str;
    bool possible = true;
    int n;
    int len;
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        n = str.size();
        len = combinationLength;
        
        bits.resize(n, 0);
        
        for(int i = 0; i < len; i++) {
            bits[i] = 1;
        }
    }
    
    string next() {
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            if(bits[i])
                ans += str[i];
        }
        
        if(bits[n - 1] == 0) {
            for(int i = n - 1; i >= 0; i--) {
                if(bits[i]) {
                    bits[i + 1] = 1;
                    bits[i] = 0;
                    break;
                }
            }
        } 
        else {
            
            int onesAtLast = 0;
            int i = n - 1;
            while(i >= 0 && bits[i]) {
                bits[i] = 0;
                onesAtLast++;
                i--;
            }
            
            
            if(onesAtLast == len) {
                possible = false;
            } else {
                
                
                while(i >= 0 && bits[i] == 0) {
                    i--;
                }
                
                
                bits[i++] = 0;
                bits[i++] = 1;
                
                while(onesAtLast--) {
                    bits[i++] = 1;
                }
            }
        }
        
        return ans;
    }
    
    bool hasNext() {
        return possible;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */