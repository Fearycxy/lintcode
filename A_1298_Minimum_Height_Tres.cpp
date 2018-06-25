class Solution {
public:
    /**
     * @param n: n nodes labeled from 0 to n - 1
     * @param edges: a undirected graph
     * @return:  a list of all the MHTs root labels
     */
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        // Wirte your code here
        vector<vector<int>> vec(n);
        for(auto a:edges){
            vec[a[0]].push_back(a[1]);
            vec[a[1]].push_back(a[0]);
        }
        queue<int> que;
        for(int i =0;i<n;i++){
            if(vec[i].size()==1) que.push(i);
        }
        while(n>2){
            int size = que.size();
            n -= size;
            for(int i=0;i<size;i++){
                int y = que.front();que.pop();
                for(int t:vec[y]){
                    vec[t].erase(find(vec[t].begin(),vec[t].end(),y));
                    if(vec[t].size() == 1) que.push(t);
                }
            }
        }
        vector<int> an;
        while(!que.empty()){
            an.push_back(que.front());
            que.pop();
        }
        return an;
    }
};
