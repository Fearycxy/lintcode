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
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here
         queue<pair<TreeNode *,int> > que;
        que.push(make_pair(root,0));
         vector<vector<int>> an;
         int y = 0;
         vector<int> tem;
        while(!que.empty()){
            TreeNode * s = que.front().first;
            int r = que.front().second;
            que.pop();
            if(r>y){
                y = r;
                if(r%2==0){
                    reverse(tem.begin(),tem.end());
                }
                an.push_back(tem);
                tem.clear();
            }
            if(s == NULL){
                continue;
            }
            tem.push_back(s->val);
            que.push(make_pair(s->left,r+1));
            que.push(make_pair(s->right,r+1));
           
        }
        return an;
    }
};
