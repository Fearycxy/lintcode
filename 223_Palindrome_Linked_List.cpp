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
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        if(!head|| !head->next) return true;
        auto fast=head,low = head,last = head;
        while(fast&&fast->next){
            fast =fast->next->next;
            last = low;
            low = low->next;
        }
        return isPalindrome(head,last,fast? low->next:low);
        
    }
    
    bool isPalindrome(ListNode * head ,ListNode * &r,ListNode * const end){
        if(head == end) return head->val == r->val;
        if(!isPalindrome(head->next,r,end)) return false;
        r =r->next;
        return head->val == r->val;
    }
};
