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
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode * insertionSortList(ListNode * head) {
        // write your code here
        ListNode * already= new ListNode(0);
        while(head){
            auto f =already->next;
            auto cur = head;
            head =head->next;
            ListNode * last = NULL;
            while(f && f->val < cur->val){
                last = f;
                f=f->next;
            }
            cur->next = f;
            if(last){
                last->next = cur;
            }else{
                already->next = cur;
            }
        }
        return already->next;
    }
};
