class Solution {
    // s means strechy word, o means original word
    bool isMatch(const string& s, const string& o) {
        int i = 0, j = 0;
        while (i < s.size() && j < o.size()) {
            if (s[i++] != o[j++]) {
                return false;
            }
            // cntO means number of consecutive chars in O starting from i - 1
            // cntS means number of consecutive chars in S stargin from j - 1
            int cntO = 1, cntS = 1;
            while (i < s.size() && s[i] == s[i - 1]) {
                ++i;
                ++cntS;
            }
            while (j < o.size() && o[j] == o[j - 1]) {
                ++j;
                ++cntO;
            }
            if (cntS == cntO || (cntS >= 3 && cntS > cntO)) {
                continue;
            }
            return false;
        }
        return (i == s.size() && j == o.size());
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        int ret = 0;
        for (auto& word : words) {
            if (isMatch(S, word)) {
                ++ret;
            }
        }
        return ret;
    }
};
