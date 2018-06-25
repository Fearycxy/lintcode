class Solution {
public:
    /**
     * @param target: the target string
     * @param words: words array
     * @return: whether the target can be matched or not
     */
    bool matchFunction(string &target, vector<string> &words) {
        // Write your code here
        vector<bool> visited(words.size(), false);
        return dfs(target, words, visited);
    }

    bool dfs(string target, vector<string> &words, vector<bool> &visited) {
        if (target.empty())return true;
        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            if (words[i].find(target[0]) != string::npos) {
                visited[i] = true;
                string p = target;
                if (dfs(target.erase(0, 1), words, visited)){
                    return true;
                }
                target = p;
                visited[i] = false;
            }
        }
        return false;
    }
};
