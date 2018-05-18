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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        // write your code here
        auto f1 = l1,f2 =l2;
        int ap = 0;
        auto re = new ListNode(0);
        auto r = re;
        while(f1 || f2){
            int dum = 0;
            if(f1){
                dum += f1->val;
                f1 = f1->next;
            }
            if(f2){
                dum += f2->val;
                f2 = f2->next;
            }
            int xp = dum + ap > 9?1 :0;
            auto p = new ListNode((dum+ap)%10);
            ap = xp;
            r ->next = p;
            r = p;
        }
        if(ap) r->next = new ListNode(1);
        return re->next;
    }
};
