class Solution {
public:
    int findMissing2(int n, string &str) {
        set<int> result;
        set<int> path;
        dfs(result, path, 0, n, str);
        int next = 1;
        for (auto iter = result.begin(); iter != result.end(); ++iter) 
            if(*iter != next++) return next-1;
        return n;
    }
    
    void dfs(set<int>& result, set<int>& path, int index, int n, string& str) {
        if(!result.empty())return;
        if (index == str.length() && path.size() == n - 1) {
            result = path;
            return;
        }
        for (int i = 1; i <= 2; ++i) {
            if (index + i > str.length()) break;
            string word = str.substr(index, i);
            int w = stoi(word);
            if (word[0] == '0' || w > n || path.find(w) != path.end()) continue;
            path.insert(w);
            dfs(result, path, index + i, n, str);
            path.erase(w);
        }
    }
};
