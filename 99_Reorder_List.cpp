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
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        // write your code here
        if(!head || !head ->next){
            return;
        }
        ListNode *fast = head;
        ListNode * slow =head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow ->next;
        }
        slow = slow ->next;//reverse
        if(slow){
            fast =slow->next;
            while(slow && fast){
                ListNode *tem =fast;
                fast->next = slow;
                fast = tem->next;
                slow = tem;
            }
        }
        while(slow){
            cout<<slow->val<<endl;
            ListNode *tem = head->next;
            head->next = slow;
            slow = slow->next;
            head->next->next = tem;
            head = tem;
        }
    }
};//这傻逼Lintcode打日志都走到return了还是超时无限循环，害的老子找了半天
