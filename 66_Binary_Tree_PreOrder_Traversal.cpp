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
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        preorder(root);
        return re;
        
    }
    
private:

    void preorder(TreeNode *root){
         if(root !=NULL){
             re.push_back(root->val);
             preorder(root->left);
             preorder(root->right);
         }
     }
    
};
