/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
   typedef RandomListNode Node;
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        Node *it = head;
        while(it){//first step copy
            Node* tem = new Node(it->label);
            tem->next = it->next;
            it->next = tem;
            it = tem->next;
        }
        //second copy random
        it = head;
        while(it){
            if(it->random){
                it->next->random = it->random->next;
            }else{
                 it->next->random = NULL;
            }
            it = it ->next->next;
        }
        //finally
        it = head;
        Node * tem = new Node(0);
        Node * an = tem;
        while(it){
            tem->next = it->next;
            tem = tem->next;
            it ->next = tem->next;
            it = tem->next;
        }
        return an->next;
        
    }
};
