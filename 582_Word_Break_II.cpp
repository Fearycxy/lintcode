class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string s, unordered_set<string> wordDict) {
        // write your code here
        int n = s.size();
        bool total[n + 1] = {false};
        bool dp[n + 1] = {false};
        dp[n] = true;
        vector<vector<string>> vec(n + 1);
        total[0] = true;
        for (int i = n - 1; i >= 0; i--)
            if (dp[i + 1])
                for (int j = i; j >= 0; j--)
                    if (wordDict.count(s.substr(j, i - j + 1)))
                        dp[j] = true;

        for (int i = 0; i < n; i++) {
            if (!total[i] || !dp[i]) continue;
            for (int j = i; j < n; j++) {
                string seg = s.substr(i, j - i + 1);
                if (wordDict.count(seg)) {
                    if ((vec[i]).empty())
                        vec[j + 1].push_back(seg);
                    else
                        for (string &pre:vec[i])
                            vec[j + 1].push_back(pre + " " + seg);
                    total[j + 1] = true;
                }
            }
        }
        return vec[n];
    }
};
