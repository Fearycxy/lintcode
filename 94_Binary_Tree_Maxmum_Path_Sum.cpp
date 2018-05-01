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
     * @param root: The root of binary tree.
     * @return: An integer
     */
     int an ;
    int maxPathSum(TreeNode * root) {
        // write your code here
        an = INT_MIN;
        an = max(helper(root),an);
        return an;
    }
    
    int helper(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int l = helper(root->left);
        if(l<0){
            l = 0;
        }
        int r = helper(root->right);
        if(r<0){
            r = 0;
        }
        an = max(l+r+root->val,an);
        int re = max(l,r)+root->val;
        return re;
    }
};
