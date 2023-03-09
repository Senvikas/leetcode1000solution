class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            if (!st.insert(cur).second) return *st.insert(cur).first;
            cur = cur->next;
        }
        return NULL;
    }
};
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next ) return NULL;
        ListNode* fast = head, *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast ){
                slow = head;
                while(slow != fast ) slow = slow->next, fast = fast->next;
                return slow;
            }
        }
        return NULL;
    }
};
*/