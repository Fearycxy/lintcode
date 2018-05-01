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
vector<int> tem;
vector<int> a;
int type;
int x,y;
TreeNode * re;
    void inorder(TreeNode * root){
         if(root==NULL){
             return ;
         }
         a.push_back(0);
         inorder(root->left);
         a.pop_back();
         if(dosome(root)){
             return;
         }
         a.push_back(1);
         inorder(root->right);
         a.pop_back();
     }
     int dosome(TreeNode *node){
         switch(type){
             case 0:
             if(node->val ==x||node->val ==y ){
                 if(tem.size()==0){
                     tem =a;
                 }else{
                     auto it = a.begin();
                     auto tt = tem.begin();
                     while(it!=a.end()&&tt!=tem.end()){
                         if(*it!=*tt){
                             break;
                         }
                         it++;
                         tt++;
                     }
                     tem.erase(tt,tem.end());
                     return 1;
                 }
             }
                break;
            case 1:
                if(a==tem){
                    re = node;
                    return 1;
                }
                break;
         }
         return 0;
     }
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        type = 0;
        x = A->val;
        y = B->val;
        inorder(root);
        type =1;
        inorder(root);
        return re;
    }
};
