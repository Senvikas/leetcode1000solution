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
    int pairSum(ListNode* head) {
        int n = 0; auto t = head;
        while(head){
            head=head->next;
                n++;
        }
        //cout << n << endl;
       vector<int>arr(n); int i = 0; head = t;
        while(head){
            arr[i] = head->val;
            head = head -> next;
            i++;
        }
            int ans = 0;
        i = 0;
        while(i <= n){
            ans = max(ans, arr[i] + arr[n-1]);
            i++; n--;
        }
        return ans;
    }
};