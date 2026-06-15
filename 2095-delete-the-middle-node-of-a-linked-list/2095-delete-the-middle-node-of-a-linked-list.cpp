/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getlen(ListNode* head){
        int l = 1;
        while(head->next){
            l++; head =head->next;
        }
        return l;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* tmp = head;
        int len = getlen(head);
        cout<<len;
        if(len == 1) return nullptr;
        int mid = len/2;
        cout<<mid;
        while(mid>1){
            mid--;
            tmp = tmp->next;
        }
        ListNode* to_dlt = tmp->next;
        tmp->next = to_dlt ->next;
        delete to_dlt;
        
        return head;
    }
};