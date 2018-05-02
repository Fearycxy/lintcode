/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
        // write your code here
        return sortedListToBST(head,NULL);
    }
    
    TreeNode * sortedListToBST(ListNode * head,ListNode * tail) {
        // write your code here
        if(!head || head == tail){
            return NULL;
        }
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast !=tail && fast->next !=tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode * re = new TreeNode(slow->val);
        re ->left = sortedListToBST(head,slow);
        re->right = sortedListToBST(slow->next,tail);
        return re;
        
    }
};

//九章的要好些
class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
        // write your code here
        return inorder(head,getSize(head));
    }
    
    TreeNode * inorder(ListNode *&head,int size){//size 表示以此节点为根节点的子树的节点个数
   
        if(size == 0){
            return NULL;
        }
        TreeNode * root = new TreeNode(0);
        root->left = inorder(head,size/2);
        root ->val = head->val;
        head = head ->next;
        root->right =  inorder(head,size - 1 -size/2);
        return root;
    }
    
    int getSize(ListNode *head){
        int i = 0;
        while(head){
            i++;
            head = head->next;
        }
        return i;
    }
};
