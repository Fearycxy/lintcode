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
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        auto re = head;
        while(head&&head->next){
            if(head->val == head->next->val){
                head->next = head->next->next;
            }else{
                head= head->next;
            }
        }
        return re;
        
    }
};
