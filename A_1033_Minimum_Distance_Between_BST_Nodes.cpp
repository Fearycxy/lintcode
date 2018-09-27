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
class BSIterator{
public:
    BSIterator(TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    bool hasNext(){
        return !st.empty();
    }
    
    int next(){
        TreeNode * a = st.top();
        st.pop();
        int f = a->val;
        a = a->right;
        while(a){
            st.push(a);
            a = a->left;
        }
        return f;
    }
private:
    stack<TreeNode *> st;
};
class Solution {
public:
    /**
     * @param root: the root
     * @return: the minimum difference between the values of any two different nodes in the tree
     */
    int minDiffInBST(TreeNode * root) {
        // Write your code here
        BSIterator it(root);
        int last = it.next(),re = INT_MAX;
        while(it.hasNext()){
            int l = it.next();
            re = min(re,l-last);
            last = l;
        }
        return re;
    }
    
   
};
