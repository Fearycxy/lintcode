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
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        int re = 0;
        help(root,target,INT_MAX,re);
        return re;
    }
    
    void help(TreeNode * root, double target,double diff,int &re){
        if(!root) return;
        if(abs(root->val - target) < diff){
            diff = abs(root->val - target);
            re = root->val;
        }
        auto k= target>root->val? root->right:root->left;
        help(k,target,diff,re);
    }
};
