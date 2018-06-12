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
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        int re =0, y = 1;
        dfs(root,y,k,re);
        return re;
    }
    
    void dfs(TreeNode * root,int& y,const int k,int& re){
        if(!root) return;
        if(k<y) return;
        dfs(root->left,y,k,re);
        if(y++ ==k){
            re = root->val;
            return;
        }
        dfs(root->right,y,k,re);
    }
};
