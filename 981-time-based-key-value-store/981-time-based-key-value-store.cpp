class TimeMap {
    public:
unordered_map<string,unordered_map<int,string>>map;

TimeMap() {
    
}

void set(string key, string value, int timestamp) {
    map[key][timestamp]=value;
}

string get(string key, int timestamp) {
    
    
       
     while(map[key][timestamp]=="" && timestamp>=0){
            timestamp--;
     }
        
        
    
    return map[key][timestamp];
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */