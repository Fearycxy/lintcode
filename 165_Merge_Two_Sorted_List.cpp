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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode *re = new  ListNode(0);
        auto head = re;
        while(l1 || l2){
            while(l1 && (!l2 || l1->val <= l2->val)) {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            }
             while(l2 && (!l1 || l2->val <= l1->val)) {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        return re->next;
    }
};
