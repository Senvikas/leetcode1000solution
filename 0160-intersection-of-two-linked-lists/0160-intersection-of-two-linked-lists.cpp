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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        auto tmp = headA, tmp2 = headB;
        
        while(tmp || tmp2){
            if(!tmp && !tmp2) return NULL;
            
            if(!tmp){
                tmp = headB;
               // tmp2 = tmp2->next;
            }
            else if(!tmp2){
                tmp2 = headA;
               // tmp = tmp->next;
            }
            
            if(tmp == tmp2) return tmp;
            
            tmp = tmp->next;
            tmp2 =tmp2->next;
        }
        
        return nullptr;
    }
};