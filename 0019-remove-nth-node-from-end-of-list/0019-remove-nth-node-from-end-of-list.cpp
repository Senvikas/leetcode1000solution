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
    int getLen(ListNode* head){
        auto tmp = head;
        int cnt = 0;
        
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);
        n = len - n + 1;  // from first;
        if(n==0 || n>len) return head;
        if(n == 1) return head->next;
        
        auto tmp = head;
        
        while(n>2){
            tmp = tmp->next;
            n--;
        }
        
        tmp->next = tmp->next->next;
        return head;
    }
};