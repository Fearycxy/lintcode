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
     * @param head: head is the head of the linked list
     * @return: head of the linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        if(!head){
            return NULL;
        }
        auto re = new ListNode(0);
        re->next = head;
        auto lastnode = re;
        int last = INT_MIN;
        while(head){
            if(head->val == last){
                lastnode->next = head->next;
            }else{
                if(head->next && head->next->val != head->val)
                    lastnode = head;
                last = head->val;
            }
            head= head->next;
        }
        return re->next;
    }
};
