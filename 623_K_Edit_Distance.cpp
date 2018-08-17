class node {
public:
    bool is_end = false;
    node *child[26]{};
    string word ;
};

void insert(node *root, string &s) {
    for (char c:s) {
        if (!(root->child)[c - 'a']) (root->child)[c - 'a'] = new node;
        root = (root->child)[c - 'a'];
    }
    root->word = s;
    root->is_end = true;
}

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        vector<string> an;
        node p;
        for (auto &s:words) insert(&p, s);
        vector<int> dp(target.size() + 1);
        for (int i = 0; i < target.size() + 1; i++)dp[i] = i;
        dfs(an, target, k, &p, dp);
        return an;
    }

    void dfs(vector<string> &an, string &target, int k, node *p, vector<int> &dp) {
        if (p->is_end && dp[target.size()] <= k) an.push_back(p->word);
        for (int i = 0; i < 26; i++) {
            if (!p->child[i]) continue;
            vector<int> nextdp(target.size() + 1, dp[0] + 1);
            for (int j = 1; j < nextdp.size(); j++) {
                if ('a' + i == target[j - 1]) {
                    nextdp[j] = dp[j - 1];
                } else {
                    nextdp[j] = min(nextdp[j - 1], min(dp[j], dp[j - 1])) + 1;
                }
            }
            dfs(an, target, k, p->child[i], nextdp);
        }
    }
};
