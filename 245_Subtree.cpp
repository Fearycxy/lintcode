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
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
     bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here
        return !T2 || help(T1,T2,T2);
    }
    
    bool help(TreeNode * const T1, TreeNode * const T2,TreeNode * const o2){
        if(!T2) return !T1;
        if(!T1) return false;
        if(T1->val == T2->val&&help(T1->left,T2->left,o2) &&help(T1->right,T2->right,o2)){
            return true;
        }
        if(T2 != o2) return help(T1,o2,o2);
        return help(T1->left,o2,o2) || help(T1->right,o2,o2);
    }
};
