/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        // write your code here
        auto la = headA,lb = headB;
        int l1 =0,l2=0;
        while(la){
            l1++;
            la = la->next;
        }
        while(lb){
            l2++;
            lb = lb->next;
        }
        if(l1>l2){
            for(int i = l1-l2;i>0;i--) headA = headA->next;
        }else{
            for(int i = l2-l1;i>0;i--) headB = headB->next;
        }
        while(headA){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
