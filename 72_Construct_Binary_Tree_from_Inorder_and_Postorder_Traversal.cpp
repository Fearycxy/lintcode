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
  typedef vector<int>::iterator VIT;
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if(inorder.size()==0){
            return NULL;
        }
        return build(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
private:
    TreeNode * build(VIT instart,VIT inend,VIT postart,VIT posend){
        if(instart >= inend){
            return NULL;
        }
        VIT head = posend-1;
        int val = *head;
        VIT next = find(instart,inend,val);
        TreeNode * node = new TreeNode(val);
        node->left = build(instart,next,postart,postart+(next-instart));
        node ->right = build(next+1,inend,postart+(next-instart),posend-1);
        return node;
    }
};
