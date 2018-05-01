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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next &&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow ->next;
        slow->next =NULL;
        slow = sortList(head);
        fast = sortList(fast);
        return merge(slow,fast);
    }
    
    ListNode * merge(ListNode * f,ListNode *s){
        if(!f){
            return s;
        }else if(!s){
            return f;
        }
        ListNode head(0);
        ListNode *tem = &head;
        while(f&&s){
            if(f->val < s->val){
                tem->next = f;
                f = f->next;
            }else{
                tem->next = s;
                s = s->next;
            }
            tem = tem->next;
        }
        if(f){
            tem->next = f;
        }else{
            tem->next = s;
        }
        return head.next;
    }
};
