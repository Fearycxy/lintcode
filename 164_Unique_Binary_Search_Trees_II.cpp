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
map<int,vector<TreeNode* >> mp;
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        if(mp.count(n)){
            return mp[n];
        }
        vector<TreeNode*> re;
        if(n==0){
            re.push_back(NULL);
        }else if(n ==1){
            re.push_back(new TreeNode(1));
        }else{
            for(int l = 0;l<n;l++){
                for(auto lt:generateTrees(l)){
                    for(auto rt:generateTrees(n-1-l)){
                        TreeNode * root = new TreeNode(l+1);
                        root->left = lt;
                        root->right = help(rt,l+1);
                        re.push_back(root);
                    }
                }
            }
        }
         mp[n] = re;
         return re; 
    }
    
    TreeNode * help(TreeNode * root,int s){
        if(!root) return NULL;
        TreeNode * f = new TreeNode(root ->val + s);
         f->left = help(root->left,s);
         f ->right = help(root->right,s);
         return f;
    }
};
