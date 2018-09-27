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
     * @param root: 
     * @return: the length of the longest path where each node in the path has the same value
     */
    int longestUnivaluePath(TreeNode * root) {
        // Write your code here
        int an = 0;
        if(!root) return 0;
        singlePath(root,an);
        return an;
    }
    
    int singlePath(TreeNode *root,int & an){
        int re = 0, l = 0, r = 0,z=0,y=0;
        if(root->left){
            l = singlePath(root->left,an);
            if(root->left->val == root->val) z = l+1;
        }
        if(root->right){
            r = singlePath(root->right,an);
            if(root->right->val == root->val) y = r+1;
        }
        an = max(an,y+z);
        return max(z,y);
    }
}
