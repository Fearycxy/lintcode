class Solution {
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string> words) {
        // Write your code here
        unordered_map<string, unordered_set<int>> m;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); j++) {
                string t = words[i].substr(words[i].size() - j, j);
                string p = words[i].substr(0, words[i].size() - j);
                if (isValid(t)) {
                    string p1 = p;
                    reverse(p1.begin(), p1.end());
                    m[p1].insert(i + 1);
                }
                if (isValid(p)) {
                    string t1 = t;
                    reverse(t1.begin(), t1.end());
                    m[t1].insert(-(i + 1));
                }
            }
        }
        auto y = [](const std::vector<int> &p) {
            return std::hash<int>()(p[0]) ^ std::hash<int>()(p[1]);
        };
        unordered_set<vector<int>, decltype(y)> re(0, y);
        for (int i = 0; i < words.size(); i++) {
            for (int j:m[words[i]]) {
                if (abs(j) - 1 != i) {
                    if (j > 0) re.insert({j - 1, i});
                    else re.insert({i, abs(j) - 1});
                }
            }
        }
        return vector<vector<int>>(re.begin(), re.end());
    }

    inline bool isValid(string &t) {
        for (int i = 0; i < t.size() / 2; i++) {
            if (t[i] != t[t.size() - i - 1]) return false;
        }
        return true;
    }

};
