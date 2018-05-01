/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode *head = new ListNode(0);
        ListNode *re = head;
        while(true){
            bool flag = true;
            int m = INT_MAX;
            for(auto it =lists.begin();it !=lists.end();it++){
               if((*it) !=NULL){
                   flag = false;
                   m  = min((*it)-> val,m);
               }
               
            }
            if(flag){
                break;
            }
            for(auto it =lists.begin();it !=lists.end();it++){
               if((*it) !=NULL && (*it)->val == m){
                   head->next = *it;
                   head = *it;
                   *it = (*it)->next;
               }    
               
            }
        }
        return re->next;
    }
};



