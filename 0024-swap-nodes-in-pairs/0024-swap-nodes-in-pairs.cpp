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
    ListNode* swapPairs(ListNode* head) {
        auto t = head;
        while(t && t->next){
            int fv = t->val;
            int lv = t->next->val;
            t->val = lv;
            t->next->val = fv;
            t = t->next->next;
        }
        return head;
    }
};