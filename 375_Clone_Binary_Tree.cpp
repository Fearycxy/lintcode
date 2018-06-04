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
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    TreeNode * cloneTree(TreeNode * root) {
        // write your code here
        if(!root) return NULL;
        TreeNode* re = new TreeNode(root->val);
        re->left = cloneTree(root->left);
        re->right = cloneTree(root->right);
        return re;
    }
};
