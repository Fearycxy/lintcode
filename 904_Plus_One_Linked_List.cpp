/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        // Write your code here
       auto y = reverse(head),t =y;
        int p = 1,u ;
        while(y){
            u  = y->val += p;
            if(u>=10) y->val = u%10;
            else break;
            if(y->next) y = y->next;
            else {
                y->next = new ListNode(1);
                break;
            }
        }
        return reverse(t);
    }
    
    inline ListNode * reverse(ListNode * head){
         ListNode* root = new ListNode(0);
        while(head){
            auto tem = head->next;
            head->next = root->next;
            root->next = head;
            head = tem;
        }
        return root->next;
    }
};
