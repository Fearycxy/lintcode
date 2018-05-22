//1.通过入度来判断可以看成拓扑排序
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if(edges.empty()) return n<=1;
        int a[n] = {0};
        for(auto &s:edges){
            for(int f:s){
                a[f]++;
            }
        }
        for(int f:a){
            if(!f) return false;
        }
        bool flag = true;
        while(flag){
            flag = false;
          for(auto it = edges.begin();it != edges.end();){
              auto c = *it;
                if(a[c[0]]<=1 || a[c[1]]<=1){
                    flag = true;
                    it = edges.erase(it);
                    a[c[0]]--;
                    a[c[1]]--;
                }else it++;
            }
        }
        return edges.empty();
    }
};

//2，并查集
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        UnionFind f(n);
        for(auto &s:edges){
            if(!f.bind(s[0],s[1])){
                return false;
            }
        }
        return f.size() == 1;
    }

    class UnionFind{
    private:
        int n;
        int* ids;
        int count;
    public:
        UnionFind(int n){
            this->n = n;
            ids = new int[n];
            for(int i=0;i<n;i++){
                ids[i] = i;
            }
            count = n;
        }

        int find(int i){
            return ids[i];
        }

        bool bind(int x,int y){
            int src = find(x);
            int drc = find(y);
            if(src == drc){
                return false;
            }else{
                for(int i = 0;i<n;i++){
                    if(ids[i]==drc){
                        ids[i] = src;
                    }
                }
                count--;
                return true;
            }
        }

        ~UnionFind(){
            delete[] ids;
        }

        int size(){
            return count;
        }
    };
};

//3. bfs version
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        v.insert(0);
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (v.find(a) != v.end()) return false;
                v.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return v.size() == n;
    }
};
