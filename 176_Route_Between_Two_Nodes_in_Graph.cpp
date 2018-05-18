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
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_map<DirectedGraphNode*,bool> flag;
        queue<DirectedGraphNode*> que;
        que.push(s);
        while(!que.empty()){
            auto cur = que.front();que.pop();
            if(cur==t){
                return true;
            }
            for(auto &nei:cur->neighbors){
                if(!flag.count(nei) || !flag[nei]){
                    que.push(nei);
                }
            }
        }
        return false;
    }
};
