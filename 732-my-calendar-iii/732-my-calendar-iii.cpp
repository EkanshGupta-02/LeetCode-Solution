class MyCalendarThree {
public:
    map<int,int>m;
int c1=0,c2=0;
MyCalendarThree() {
    
}

int book(int start, int end) {
  ++m[start];
    --m[end];
    for(auto it=m.begin();it!=m.end();it++)
    {
        c1+=it->second;
        c2=max(c1,c2);
    }
    return c2;
}
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */