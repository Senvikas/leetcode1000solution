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
        set <ListNode*> st;
        
        auto tmp = headA;
        while(tmp){
            st.insert(tmp);
            tmp = tmp->next;
        }
        
        tmp = headB;
        while(tmp){
            if(st.find(tmp) != st.end()) return tmp;
            tmp = tmp->next;
        }
        
        return NULL;
    }
};