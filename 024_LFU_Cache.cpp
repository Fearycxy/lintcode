#include <list>

class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) {
        // do intialization if necessary
        mCapacity = capacity;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if(mCapacity<=0) return;
        if(get(key) != -1){
            mp[key].first = value;
            return;
        }
        if(mp.size()>=mCapacity){
            mp.erase(freq[minFre].front());
            iter.erase(freq[minFre].front());
            freq[minFre].pop_front();
        }
        mp[key] = {value,1};
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFre = 1;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if(mp.find(key) == mp.end()) return -1;
        freq[mp[key].second].erase(iter[key]);
        mp[key].second++;
        freq[mp[key].second].push_back(key);
        iter[key] = --freq[mp[key].second].end();
        if(freq[minFre].empty()) minFre++;
        return mp[key].first;
    }
private:
    int mCapacity;
    unordered_map<int,pair<int,int>> mp;//(key,pair<value,freq>)
    unordered_map<int,list<int>> freq;//(freq,list<key>)
    unordered_map<int,list<int>::iterator> iter;//(key,iterator)
    int minFre ;
};
