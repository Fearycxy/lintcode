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
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        // write your code here
        int nouse=0,use=0;
        help(root,nouse,use);
        return max(use,nouse);
    }
    
    void help(TreeNode *root,int &no_use,int &use){
         if(!root) return;
         int left_no=0,left_use=0,right_no=0,right_use=0;
         help(root->left,left_no,left_use);
         help(root->right,right_no,right_use);
         no_use = max(left_use,left_no)+max(right_use,right_no);
         use = left_no+right_no+root->val;
    }
};
