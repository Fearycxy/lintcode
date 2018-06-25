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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        // write your code here
        int ml = 1;
        dfs(root,-2,0,ml);
        return ml;
    }
    
    void dfs(TreeNode *root,int last,int l,int& ml){
        if(!root) return;
        if(root->val == last+1) {
            l++;
            if(l>=ml) ml = l;
        }else l = 1;
        dfs(root->left,root->val,l,ml);
        dfs(root->right,root->val,l,ml);
    }
};
