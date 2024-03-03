/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int getLen(ListNode *head)
        {
            auto tmp = head;
            int cnt = 0;

            while (tmp)
            {
                cnt++;
                tmp = tmp->next;
            }

            return cnt;
        }

    ListNode* rotateRight(ListNode *head, int k)
    {
        
        int n = getLen(head);
        if(k==0 || n==0) return head;
        k = k % n;
        if(k==0) return head;
        auto tmp = head;
        int cnt = n - k;
        while (cnt > 1)
        {
            tmp = tmp->next;
            cnt--;
        }
        
        auto store = tmp->next;
        tmp->next = nullptr;
        
        tmp = store;
        
        while(tmp->next) tmp=tmp->next;
        tmp->next = head;
        
        return store;
    }
};