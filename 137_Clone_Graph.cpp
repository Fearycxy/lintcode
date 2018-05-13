/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        if(!node){
            return NULL;
        }
        map<int,UndirectedGraphNode*> mp;
        queue<UndirectedGraphNode*> que;
        UndirectedGraphNode* var = new UndirectedGraphNode(node->label);
        var->neighbors = node->neighbors;
        mp[node->label] = var;
        que.push(var);
        while(!que.empty()){
            auto cur = que.front();que.pop();
            for(auto &v:cur->neighbors){
                if(mp.count(v->label)){
                    v = mp[v->label];
                }else{
                    auto t = new UndirectedGraphNode(v->label);
                    t ->neighbors = v->neighbors;
                    v = t;
                    mp[v->label] = v;
                     que.push(v);
                }
            }
        }
        return var;
    }
};
