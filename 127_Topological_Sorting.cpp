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
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        vector<DirectedGraphNode*> an;
        map<DirectedGraphNode*,int> mp;
        for(auto node = graph.begin();node != graph.end();node++)
            for(auto it = (*node)->neighbors.begin();it != (*node)->neighbors.end();it++)
                mp.count(*it)? mp[*it]++: mp[*it] =1;
         for(auto node = graph.begin();node != graph.end();node++){
             if(mp[*node] == 0){
                 dps(*node, graph,mp,an);
             }
         }
        return an;
    }
    
private: 
    void dps(DirectedGraphNode* node,vector<DirectedGraphNode*>& graph,map<DirectedGraphNode*,int> &mp, vector<DirectedGraphNode*> &an){
        mp[node]--;
        an.push_back(node);
        for(auto it = node->neighbors.begin();it != node->neighbors.end();it++){
            if(--mp[*it] ==0){
                dps(*it,graph,mp,an);
            }
        }
        
    }
};
