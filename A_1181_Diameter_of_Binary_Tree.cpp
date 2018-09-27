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
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        // write your code here
        int re = 0;
         dfs(root,re);
        return re;
    }
    
    int dfs(TreeNode * root,int& re){
        int l =0, r =0;
        if(root->left) l = dfs(root->left,re)+1;
        if(root->right) r = dfs(root->right,re)+1;
        re = max(l+r,re);
        return max(l,r);
    }
};
