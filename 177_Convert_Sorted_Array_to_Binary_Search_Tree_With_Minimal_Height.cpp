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
    /*
     * @param A: an integer array
     * @return: A tree node
     */
    TreeNode * sortedArrayToBST(vector<int> A) {
        // write your code here
        int n = A.size();
        if(n == 0) return NULL;
        TreeNode *re = new TreeNode(A[(n-1)/2]);
        re ->left = sortedArrayToBST(vector<int>(A.begin(),A.begin()+(n-1)/2));
        re ->right = sortedArrayToBST(vector<int>(A.begin()+(n-1)/2+1,A.end()));
        return re;
    }
};
