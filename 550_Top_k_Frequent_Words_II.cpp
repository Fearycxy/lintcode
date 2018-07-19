class TopK {
public:
unordered_map<string, int> freq;
map<int,set<string>> mp;
int d ;
    /*
    * @param k: An integer
    */TopK(int k) {
        // do intialization if necessary
        d = k;
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        auto y = mp[freq[word]].find(word);
        if (y != mp[freq[word]].end()) mp[freq[word]].erase(y);
        ++freq[word];
        mp[freq[word]].insert(word);
        // write your code here
    }

    /*
     * @return: the current top k frequent words.
     */
    vector<string> topk() {
        // write your code here
        int k = d;
        vector<string> res;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            if (k <= 0) break;
            auto t = it->second;
            vector<string> v(t.begin(), t.end());
            res.insert(res.end(), v.begin(), k >= t.size()?v.end():v.begin() + k);
            k -= t.size();
        }
        return res;
    }
};
