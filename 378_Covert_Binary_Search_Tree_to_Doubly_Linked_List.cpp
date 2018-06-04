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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode * bstToDoublyList(TreeNode * root) {
        // write your code here
        DoublyListNode *re= NULL,*pre = NULL;
        dfs(root,pre,re);
        return re;
    }
    
    void dfs(TreeNode * root,DoublyListNode * &pre,DoublyListNode *&head){
        if(!root) return;
        dfs(root->left,pre,head);
        DoublyListNode * cur = new DoublyListNode(root->val);
        if(!head) head = cur;
        cur->prev = pre;
        if(pre)pre->next = cur;
        pre = cur;
        dfs(root->right,pre,head);
    }
};
