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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto tmp = l1;
        auto tmp2 = l2;
        
        auto dummy = new ListNode(-1);
        auto dt = dummy;
        
        while(tmp && tmp2){
            int sum = tmp->val + tmp2->val + carry;
            carry = sum/10;
            auto node = new ListNode(sum%10);
            dt->next = node;
            dt = node;
            
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        while(tmp){
            int sum = tmp->val + carry;
            carry = sum/10;
            auto node = new ListNode(sum%10);
            dt->next = node;
            dt = node;
            
            tmp = tmp->next;
        }
        
        while(tmp2){
            int sum = tmp2->val + carry;
            carry = sum/10;
            auto node = new ListNode(sum%10);
            dt->next = node;
            dt = node;
            
            tmp2 = tmp2->next;
        }
        
        if(carry) dt->next = new ListNode(1);
        
        return dummy->next;
    }
};