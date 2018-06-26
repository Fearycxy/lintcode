#include <list>

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        // do intialization if necessary
        mCapacity = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if(mp.find(key)==mp.end()) return -1;
        moveToHead(key);
        return mp[key]->second;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if(mp.find(key)!=mp.end()){
            moveToHead(key);
            mp[key]->second = value;
        }else{
            while(lru.size()>=mCapacity){
                mp.erase(lru.back().first);
                lru.pop_back();
            }
            lru.emplace_front(key,value);
            mp[key] = lru.begin();
        }
    }
private:
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int mCapacity;
    int moveToHead(int key){
        auto entry = *mp[key];
        lru.erase(mp[key]);
        lru.push_front(entry);
        mp[key] = lru.begin();
    }
};
