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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        ListNode * newh = new ListNode(0);
        ListNode *X = new ListNode(x);
        newh -> next = X;
        X -> next =head;
        ListNode * pre = newh;
        ListNode * before = X;
        while(head !=NULL){
            if(head->val<x){
                ListNode* f = head;
                before ->next = head->next;
                head = head->next;
                f->next = X;
                pre->next = f;
                pre = f;
            }else{
                before = head;
                head = head->next;
            }
        }
        pre->next = X->next;
        return newh->next;
    }
};
