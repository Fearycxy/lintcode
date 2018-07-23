class Solution {
public:
    /**
     * @param x: The x
     * @param y: The y
     * @param a: The a
     * @param b: The b
     * @return: The Answer
     */
    vector<int> tree(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b) {
        // Write your code here
        unordered_map<int,int> mp;
        unordered_map<int,unordered_set<int>>line;
        queue<int> que;
        for(int i=0;i<x.size();i++){
            if(x[i]==1 && y[i]==1)continue;
             if(x[i]==1) {
                 mp[y[i]] =1;
                 que.push(y[i]);
             }else if(y[i]==1) {
                 mp[x[i]] =1;
                 que.push(x[i]);
             }else{
                 line[x[i]].insert(y[i]);
                 line[y[i]].insert(x[i]);
             }
        }
        while(!que.empty()){
            int f = que.front();
            que.pop();
            for(int u:line[f]){
                if(u!=f && u!=mp[f]){
                    mp[u] = f;
                    que.push(u);
                }
            }
        }
        vector<int> an;
        for(int i=0;i<a.size();i++){
            if(mp[a[i]]==b[i] || mp[b[i]]==a[i]){
                an.push_back(2);
            }else if(mp[a[i]]==mp[b[i]] ){
                an.push_back(1);
            }else{
                an.push_back(0);
            }
        }
        return an;
    }
};
