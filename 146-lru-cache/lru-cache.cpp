class LRUCache {
private:
    int cap;
    list<int> lst;
    unordered_map<int, pair<int,list<int>::iterator>>mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        // move it to front
        lst.splice(lst.begin(), lst, mp[key].second);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].first = value;
            lst.splice(lst.begin(), lst, mp[key].second);
        } else {
            if(mp.size() == cap){
                int lru_key = lst.back();
                lst.pop_back();
                mp.erase(lru_key);
            }
            lst.push_front(key);
            mp[key] = {value, lst.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */