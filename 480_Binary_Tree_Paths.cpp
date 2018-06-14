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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<string> re;
        if(!root) return re;
        string cur ;
        dfs(re,cur,root);
        return re;
    }
    
    void dfs(vector<string> &re,string cur,TreeNode *root){
        if(root->left==NULL && root->right==NULL){
            cur += to_string(root->val);
            re.push_back(cur);
            return;
        }
        cur += to_string(root->val);
         cur += "->";
        if(root->left)dfs(re,cur,root->left);
        if(root->right)dfs(re,cur,root->right);
    }
};
