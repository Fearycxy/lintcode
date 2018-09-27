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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    BSTIterator(TreeNode * root) {
        push(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    TreeNode * next() {
        auto y = st.top();st.pop();
        push(y->right);
        return y;
    }
    
private:
    stack<TreeNode*> st;
    void push(TreeNode * root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
};
class Solution {
public:
    /**
     * @param root: the root
     * @return: the minimum absolute difference between values of any two nodes
     */
    int getMinimumDifference(TreeNode * root) {
        // Write your code here
        BSTIterator it(root);
        int last = INT_MIN,re = INT_MAX;
        while(it.hasNext()){
            int cur = it.next()->val;
            if(last != INT_MIN) re = min(re,abs(cur-last));
            last = cur;
        }
        return re;
    }
};
