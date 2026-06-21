class LRUCache {
public:
    LRUCache(int capacity) {
       cap=capacity;
    }
    
    int get(int key) {
        auto it=cache.find(key);
        if(it!=cache.end()){  
            lru.splice(lru.begin(),lru,it->second);
            return it->second->second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        auto it=cache.find(key);
        if(it!=cache.end()){
            it->second->second=value;
            lru.splice(lru.begin(),lru,it->second);
        }
        else{
            if(lru.size()>=cap){
                int old_key=lru.back().first;
                cache.erase(old_key);
                lru.pop_back();
            }
            lru.push_front({key,value});
            cache[key] = lru.begin();
        }
    }

private:
    int cap;
    std::list<std::pair<int,int>>lru;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator>cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */