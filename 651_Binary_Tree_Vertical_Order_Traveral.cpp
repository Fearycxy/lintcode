/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> vec;
        map<int,vector<int>>mp;
        queue<pair<TreeNode * ,int>> que;
        if(root) que.emplace(root,0);
        while(!que.empty()){
            auto node = que.front();que.pop();
            mp[node.second].push_back(node.first->val);
            if(node.first->left)  que.emplace(node.first->left,node.second-1);
            if(node.first->right) que.emplace(node.first->right,node.second+1);
        }
        for(auto a:mp) vec.push_back(a.second);
        return vec;
    }
};
