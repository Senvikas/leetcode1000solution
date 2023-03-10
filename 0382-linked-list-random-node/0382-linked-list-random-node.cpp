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
    int max = INT_MAX;
    vector<int> h;
    Solution(ListNode* head) {
        ListNode* list = head;
        while (list) {
            h.push_back(list->val);
            list = list->next;
        }
        max = h.size();
    }
    
    int getRandom() {
        return h[rand() % max];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */