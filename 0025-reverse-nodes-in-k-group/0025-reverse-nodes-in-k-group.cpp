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
    ListNode* reverse(ListNode* head){
        auto curr = head;
        ListNode* prev = nullptr;
        while(curr){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    int getLen(ListNode* head){
        auto tmp = head;
        int cnt = 0;
        
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        
        return cnt;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        int len = getLen(head);
        
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        auto store = head;
        cout << k << endl;
        for(int i=0; i<(len/k); i++){
            auto headd = store;
            int cnt = k-1;
            auto tmp = headd;
            
            while(cnt > 0){
                tmp = tmp->next;
                cnt--;
            }
            
            //now tmp is at kth node so reverse untill here
            store = tmp->next;
            tmp->next = nullptr;
            
            auto rev = reverse(headd);
            tail->next = rev;
            tail = headd;
        }
        tail->next = store;
        
        return dummy->next;
        
    }
};