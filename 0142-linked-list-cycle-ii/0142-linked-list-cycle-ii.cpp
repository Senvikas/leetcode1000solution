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
    ListNode *detectCycle(ListNode *head) {
        ListNode *s = head;
        ListNode *f = head;
        ListNode *st = head;
        
        if(!head || !head->next) return NULL;
        while(f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;
            if(s == f)
            {
                while(st != s)
                {
                    s = s->next;
                    st = st->next;
                }
                return st;
            }
        }
        return NULL;
    }
};