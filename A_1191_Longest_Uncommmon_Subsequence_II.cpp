class Solution {
public:
    /**
     * @param strs: List[str]
     * @return: return an integer
     */
    struct cmp {
        bool operator()(const string &a, const string &b) const {
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        }
    };

    int findLUSlength(vector<string> strs) {
        // write your code here
        map<string, int, cmp> mp;
        for (string &t:strs) mp[t]++;
        for (auto &i:mp) 
            if (i.second == 1) 
                return i.first.size();
        return -1;
    }
};
