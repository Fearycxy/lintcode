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
 typedef vector<int> VI;
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        VI vec;
        vector<VI> re;
        dfs(vec,re,root,target,0);
        return re;
    }
    
    void dfs(VI curv,vector<VI> &re,TreeNode *root,const int target,int already){
        if(!root) return;
        int s = already + root->val;
        curv.push_back(root->val);
        if(s== target && (!root->left && !root->right)){
           re.push_back(curv);
        }
            dfs(curv,re,root->left,target,s);
            dfs(curv,re,root->right,target,s);
    }
};
