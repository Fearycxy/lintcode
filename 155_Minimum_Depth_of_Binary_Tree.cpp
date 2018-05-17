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
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
        // write your code here
        int t=1,m =1;
        if(root==NULL) return 0;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
             if(!t){
                t=que.size();
                m++;
            }
            auto s = que.front();que.pop();
            t--;
            if(s->left == NULL && s->right == NULL) return m;
            if(s->left) que.push(s->left);
            if(s->right) que.push(s->right);
        }
        return m;
    }
    
};
