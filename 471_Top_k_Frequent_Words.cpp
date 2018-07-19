class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        // write your code here
        vector<string> res;
        unordered_map<string, int> freq;
        vector<set<string>> v(words.size() + 1, set<string>());
        for (string word : words) ++freq[word];
        for (auto a : freq) v[a.second].insert(a.first);
        for (int i = v.size() - 1; i >= 0; --i) {
            if (k <= 0) break;
            vector<string> t(v[i].begin(), v[i].end());
            res.insert(res.end(), t.begin(), k >= t.size()?t.end():t.begin() + k);
            k -= t.size();
        }
        return res;
    }
};
