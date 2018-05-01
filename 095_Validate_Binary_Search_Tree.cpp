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

   bool flag;

    pair<int,int> inTravel(TreeNode *root){
        auto re =make_pair(root->val,root->val);
        if(root->left !=NULL){
            auto l = inTravel(root->left);
            if(flag || l.second >=root->val){
                flag = true;
                return make_pair(INT_MAX,INT_MIN);
            }
            re.first = l.first;
        }
        if(root->right !=NULL){
            auto r = inTravel(root->right);
            if(flag || r.first<=root->val){
                flag = true;
                return make_pair(INT_MAX,INT_MIN);
            }
            re.second = r.second;
        }
        return re;
    }
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if(!root){
            return true;
        }
        flag = false;
        inTravel(root);
       return !flag;
    }
};
