class Solution {
public:
    /**
     * @param bottom: a string
     * @param allowed: a list of strings
     * @return: return a boolean
     */
    bool pyramidTransition(string &bottom, vector<string> &allowed) {
        // write your code here
        if(bottom.size()==1) return true;
        unordered_map<string,unordered_set<char>>mp;
        for(auto &y:allowed) mp[y.substr(0,2)].insert(y[2]);
        return dfs(bottom,"",mp);
    }
    
    bool dfs(string &bottom,string above,unordered_map<string,unordered_set<char>>&mp){
        int p = above.size();
        if(bottom.size()==2 && p==1) return true;
        if(p == bottom.size()-1) return dfs(above,"",mp);
        for(char c:mp[bottom.substr(p,2)])
            if(dfs(bottom,above+string(1,c),mp)) return true;
        return false;
    }
};
