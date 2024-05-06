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
    private:
        ListNode* reverse(ListNode* head){
            if(!head) return nullptr;
            
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while(curr){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            return prev;
        }
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head) return nullptr;
        stack<ListNode*> st;
        auto tmp = head;
        while(tmp){
            while(!st.empty() && st.top()->val < tmp->val){
                st.pop();
            }
            st.push(tmp);
            tmp = tmp->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        tmp = dummy;
        
        while(!st.empty()){
            tmp->next = st.top();
            tmp->next->next = nullptr;
            st.pop();
            tmp = tmp->next;
        }
        
        
        return reverse(dummy->next);
        
        
    }
};