class Solution {
public:
    /**
    * @param x: The end points set of edges
    * @param y: The end points set of edges
    * @param d: The length of edges
    * @return: Return the index of the fermat point
    */
    int getFermatPoint(vector<int> &x, vector<int> &y, vector<int> &d){
        //acyclic connected graph, V = E + 1
        int n = x.size() + 1;
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < x.size(); ++i){
            int u = x[i], v = y[i], w = d[i];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<long long> dp(n + 1, 0);
        vector<int> sz(n + 1, 0);
        countSubTree(0, 1, g, dp, sz);
        long long minDist = dp[1];
        int idx = 1;
        findPoint(0, 1, g, sz, dp[1], idx, minDist);
        return idx;
    }

private:
    void countSubTree(int from, int to, vector<vector<pair<int, int>>>& g, vector<long long>& dp, vector<int>& sz){
        sz[to] = 1;
        for (const auto& adj : g[to]){
            int v = adj.first;
            long long w = adj.second;
            if (v != from){
                countSubTree(to, v, g, dp, sz);
                sz[to] += sz[v];
                dp[to] += dp[v] + sz[v] * w;
            }
        }
    }

    void findPoint(int from, int to, vector<vector<pair<int, int>>>& g, vector<int>& sz, long long dist, int& res, long long& minDist){
        int n = sz.size() - 1;
        for (const auto& adj : g[to]){
            int v = adj.first;
            long long w = adj.second;
            if (v != from){
                long long currDist = dist - sz[v] * w + (n - sz[v]) * w;
                if (currDist < minDist){
                    minDist = currDist;
                    res = v;
                }
                findPoint(to, v, g, sz, currDist, res, minDist);
            }
        }
    }
};
