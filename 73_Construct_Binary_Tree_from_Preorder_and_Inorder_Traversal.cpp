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
typedef vector<int>::iterator vit;
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if(preorder.size()==0){
            return NULL;
        }
        return build(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
private:    
    TreeNode * build(vit pres,vit pree,vit ins,vit ine){
        if(ins == ine){
            return NULL;
        }
        int val = *pres;
        TreeNode * node = new TreeNode(val);
        vit pos = find(ins,ine,val);
        node -> left = build(pres+1,pres+1+(pos-ins),ins,pos);
        node ->right = build(pres+1+(pos-ins),ine,pos+1,ine);
        return node;
    }
};
