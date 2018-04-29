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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here
        postorder(root);
        return re;
    }
        
private:

    void postorder(TreeNode *root){
         if(root !=NULL){
             
             postorder(root->left);
             postorder(root->right);
             re.push_back(root->val);
         }
     }
};
