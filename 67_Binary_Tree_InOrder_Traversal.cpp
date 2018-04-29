
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
    vector<int> re;
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        inorder(root);
        return re;
    }
    
private:
    
    void inorder(TreeNode *root){
        if(root !=NULL){
            
            inorder(root->left);
            re.push_back(root->val);
            inorder(root->right);
        }
    }
};
