/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<int, int> mp;

    inline void bind(int p, int q) {
        if (mp.find(p) == mp.end()) mp[p] =p;
        if(mp.find(q) == mp.end()) mp[q] = mp[p];
        if (mp[p] == mp[q]) return;
        int y = mp[q];
        for (auto &it:mp)
            if (it.second == y) it.second = mp[p];
    }

    /*
     * @param nodes: a array of Directed graph node
     * @return: a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode *> nodes) {
        // write your code here
        for (auto &v:nodes) {
            bind(v->label,v->label);
            for (auto &s:v->neighbors) {
                bind(v->label, s->label);
            }
        }
        vector<int> tem;
        vector<vector<int>> an;
        unordered_map<int, vector<int>> lp;
        for (auto &v:mp) lp[v.second].push_back(v.first);
        for (auto &v:lp) an.push_back(v.second);
        return an;
    }
};
