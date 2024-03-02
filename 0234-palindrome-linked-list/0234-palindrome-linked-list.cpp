/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int getLength(ListNode *head)
        {
            if (!head)
                return 0;
            auto tmp = head;
            int cnt = 0;
            while (tmp)
            {
                cnt++;
                tmp = tmp->next;
            }
            return cnt;
        }
    ListNode* middleNode(ListNode *head)
    {
        if (!head)
            return head;
        auto slow = head;
        auto fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* iterative(ListNode *head)
    {
        auto tmp = head;
        ListNode *prev = nullptr;

        while (tmp)
        {
           	//store the list from this node onwards
            auto next = tmp->next;

           	//reverse untill this node by pointing this node's next to prev
            tmp->next = prev;

           	//update the prev as in the next iteration new prev would be tmp or prev->next;
            prev = tmp;

           	//move tmp to the next node(backup)
            tmp = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        auto mid = middleNode(head);
        int len = getLength(head);
        if (len <= 1) return true;

       	//reverse half of the list
        if (len % 2 == 1)
        {
           mid = iterative(mid->next);
        }
        else
        {
            mid = iterative(mid);
        }
        
        auto s = head;
        
        while(mid){
            if(s->val != mid->val) return false;
            s = s->next;
            mid = mid->next;
        }

        return true;
    }
};