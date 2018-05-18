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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        // write your code here
        if(!head) return head;
        ListNode *tail=head,*node = head,*test = head;
        int step = 0;
        while(test){
            step++;
            test=test->next;
        }
        k %= step;
        if(!k) return head;
        cout << k<<endl;
        step = 0;
        while(tail->next){
            if(step==k){
                node = node->next;
            }else{
                step++;
            }
            tail = tail->next;
        }
        auto re = node->next;
        node->next = NULL;
        tail->next = head;
        return re;
    }
};
