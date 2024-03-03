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
    ListNode* findMid(ListNode* head){
        auto s = head;
        auto f = head->next;
        
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        
        return s;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        auto tmp = dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp->next = l1;
                tmp = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                tmp = l2;
                l2 = l2->next;
            }
        }
        
        if(l1) tmp->next = l1;
        else tmp->next = l2;
        
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        auto mid = findMid(head);
        
        auto left = head;
        auto right = mid->next;
        mid->next = nullptr;
        
        auto leftSorted = sortList(left);
        auto rightSorted = sortList(right);
        
        return merge(leftSorted, rightSorted);
    }
};