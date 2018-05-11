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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int n = hashTable.size() * 2;
        vector<ListNode*> re (n,NULL);
        for(auto it = hashTable.begin();it != hashTable.end();it++){
            if(*it != NULL){
                auto tem = *it;
                while(tem){
                   auto h = tem;
                   tem = tem->next;
                   h->next = NULL;
                   auto f =  re[(h->val + n) % n];
                   if(f){
                       auto l = f;
                       f = f->next;
                       while(f){
                           l = f;
                           f = f->next;
                       }
                       l->next = h;
                   }else{
                       re[(h->val + n) % n] = h;
                   }
                }
            }
        }
        return re;
    }
};

