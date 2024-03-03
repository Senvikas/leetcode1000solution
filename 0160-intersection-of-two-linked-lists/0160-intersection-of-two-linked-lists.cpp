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
    int getLen(ListNode* head){
        auto tmp = head;
        int cnt = 0;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLen(headA), len2 = getLen(headB);
        
        ListNode* tmp;
        tmp = len1 > len2 ? headA : headB;
        
        int diff = abs(len1 - len2);
        while(diff){
            diff--;
            tmp = tmp->next;  
        }
        
        auto tmp2 = len1 > len2 ? headB : headA;
        
        while(tmp && tmp2){
            if(tmp == tmp2) return tmp;
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        
        return nullptr;
    }
};