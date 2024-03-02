class Solution
{
    public:
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
        return iterative(head);
    }
};