class Solution
{
    public:
        ListNode* recursive(ListNode *head)
        {
            if (!head || !head->next) return head;

           	//I'll do one part, rest recursion will take care.

           	//get the remaining list reversed by recursion
            auto reversed = recursive(head->next);

           	//traverse to end of the reversed list and attach the current node(my work)
            auto tmp = reversed;
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = head;	//curr;
           	// since head is become the last node it should point to the nullptr
            head->next = nullptr;

           	//return the reversed(head) as this contains the list in the reversed order
            return reversed;
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

    ListNode* reverseList(ListNode *head)
    {
        return recursive(head);
    }
};