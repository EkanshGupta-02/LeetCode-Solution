class CustomStack {
public:
    int* v;
    int size;
    int top;
    CustomStack(int maxSize) {
        size=maxSize;
        v = new int[size];
        top=-1;
    }
    
    void push(int x) {
        if(top==size-1){
            return;
        }
        top++;
        v[top] = x;
        return;
    }
    
    int pop() {
        if(top==-1){
            return -1;
        }
        int val = v[top];
        top--;
        return val;
    }
    
    void increment(int k, int val) {
        if(top<k){
            for(int i=0;i<=top;i++){
                v[i] += val;
            }
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */