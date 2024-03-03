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
    ListNode* sortList(ListNode* head) {
        vector<int> st;
        auto tmp = head;
        
        while(tmp){
            st.push_back(tmp->val); tmp = tmp->next;
        }
        sort(st.begin(), st.end());
        
        tmp = head;
        for(auto ele: st){
            tmp->val = ele;
            tmp = tmp->next;
        }
        
        return head;
    }
};