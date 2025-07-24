
//No splice 
// Erasing the element using its iterator (list::erase)
// Pushing the key to the front (list::push_front)
// Updating the iterator in the map
class LRUCache {
private:
    int capacity;
    list<int> lst; //front = most recent, back = least recent
    unordered_map<int, pair<int, list<int>::iterator>>mp;
public:
    LRUCache(int capacity) {  
        this->capacity = capacity;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()) return -1;// Key not found

        // Remove key from current position
        lst.erase(mp[key].second);
        // Add key to front
        lst.push_front(key);
        // Update iterator in map
        mp[key].second = lst.begin();

        return mp[key].first;
    }

    void put(int key, int value) {
         // If key already exists
        if (mp.find(key) != mp.end()) {
            lst.erase(mp[key].second);
            lst.push_front(key);
            mp[key] = {value, lst.begin()};
        } 
        // if new key found
        else {

            if (mp.size() == capacity) {// Check size
                int lru_key = lst.back();   // least recently used
                lst.pop_back();            // remove from list
                mp.erase(lru_key);       // remove from map
            }

            lst.push_front(key);// Insert new key at front
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