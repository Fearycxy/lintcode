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
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
       return quickSort(head,NULL);
    }
    
    ListNode * quickSort(ListNode * head,ListNode* tail){
         if(head == tail || head==NULL || head->next ==tail|| head->next==NULL){
             return head;//todo
         }
        ListNode * h = head;
        ListNode * th = head;
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode * lh = left;
        ListNode * rh = right;
        int value = head->val;
        head = head->next;
        while(head !=tail){
            if(value>head->val){
                left->next = head;
                left = head;
            }else if(value<head->val){
                right->next = head;
                right = head;
            }else{
                th->next = head;
                th = head;
            }
             head = head->next;
        }
        right ->next = tail;
        left->next = h;
        lh ->next = quickSort(lh->next,h);
        th->next  = quickSort(rh->next,tail);
        return lh->next;
    }
};
