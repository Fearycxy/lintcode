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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        // write your code here
        int re = 0;
        dfs(root,re);
        return re;
    }
    
private:    
    pair<int,int> dfs(TreeNode * root,int & re){
        if(!root) return {0,0};
        auto l = dfs(root->left,re);
        auto r = dfs(root->right,re);
        int lr = 1,rl = 1,in = 1,de = 1;
        if(root->left){
            if(root->left->val == root->val-1){
               lr += l.first;
               in = max(in,l.first+1);
            } 
            else if(root->left->val == root->val+1){
                rl += l.second;
                de = max(l.second+1,de);
            } 
        } 
        if(root->right){
            if(root->right->val == root->val +1 ){
                lr += r.second;
                de = max(de,r.second+1);
            } 
            else if(root->right->val == root->val -1){
                rl += r.first;
                in = max(in,r.first+1); 
            }
        }
        re = max(lr,re);
        re = max(rl,re);
        return {in,de};
    }
};
