class MinStack {
public:
    int mi;
    int tops;
    pair<int,int>*arr;
    int size;
    MinStack() {
        mi=1;
        tops=-1;
        arr = new pair<int,int>[100000];
        size=100000;
    }
    
    void push(int val) {
        if(tops+1<100000){
            tops++;
            arr[tops]={val,mi};
            if(tops==0){
                mi=0;
            }
            else{
                if(arr[mi].first>val){
                    mi=tops;
                }
            }
        }
    }
    
    void pop() {
        if(tops!=-1){
            if(mi==tops){
                mi=arr[tops].second;
            }
            tops--;
        }
        
    }
    
    int top() {
        if(tops != -1){
            return arr[tops].first;
        }
        return -1;
    }
    
    int getMin() {
        if(mi != -1 ){
            return arr[mi].first;
        }
        
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */