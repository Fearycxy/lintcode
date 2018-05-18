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
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here
        int step = 0;
        auto fast = head,slow = head;
        ListNode *last =NULL;
        while(fast){
            fast=fast->next;
            if(step<n){
                step++;
            }else{
                last = slow;
                slow = slow->next;
            }
        }
        if(last) {
            last->next = slow->next;
        }else{
            head = head->next;
        }
        return head;
    }
};
