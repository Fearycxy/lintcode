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

//version2
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        if(isDuplicate(head)) return head;
        ListNode* cur = head->next;
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* sp = small;
        ListNode* lp = large;
        while(cur){
            if(cur->val<head->val){
                sp->next = cur;
                sp = cur;
            }
            else{
                lp->next = cur;
                lp = cur;
            }
            cur = cur->next;
        }
        sp->next = NULL;
        lp->next = NULL;
        small=sortList(small->next);
        large=sortList(large->next);
        cur = small;
        if(cur){
            while(cur->next) cur = cur->next;
            cur->next = head;
            head->next = large;
            return small;
        }else{
            head->next = large;
            return head;
        }
    }
    bool isDuplicate(ListNode* head) {
        while (head) {
            if (head->next && head->next->val < head->val) {
                return false;
            }            
            head = head->next;
        }
        return true;
    }
};
