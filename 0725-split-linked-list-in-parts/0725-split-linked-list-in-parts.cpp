class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        
        tmp = head;
        vector<ListNode*> ans;
        int n = len / k, cnt = k;
        int extra = len % k; // Calculate the number of extra nodes
        
        while (cnt--) {
            int siz = n + (extra > 0 ? 1 : 0); // Distribute extra nodes among first few parts
            ListNode* dummy = new ListNode(-1);
            ListNode* tail = dummy;
            
            while (siz--) {
                tail->next = tmp;
                tail = tail->next;
                if (tmp) tmp = tmp->next;
            }
            tail->next = NULL;
            ans.push_back(dummy->next);
            
            if (extra > 0) extra--; // Decrement the count of extra nodes
        }
        return ans;
    }
};
