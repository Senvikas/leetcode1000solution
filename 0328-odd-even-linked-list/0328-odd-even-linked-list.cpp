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
/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (!head) return NULL;
            //here oh= oddhead, ot = oddtail, eh = evenhead, et = eventail
            ListNode *oh = NULL, *ot = NULL, *eh = NULL, *et = NULL;
            int cnt = 1;
            while (head)
            {
                if (cnt % 2 == 0)
                {
                    if (eh == NULL)
                    {
                        eh = head;
                        et = head;
                        head = head->next;
                    }
                    else
                    {
                        et->next = head;
                        et = et->next;
                        head = head->next;
                    }
                }
                else
                {
                    if (oh == NULL)
                    {
                        oh = head;
                        ot = head;
                        head = head->next;
                    }
                    else
                    {
                        ot->next = head;
                        ot = ot->next;
                        head = head->next;
                    }
                }
                cnt++;
            }
            if (oh == NULL) return eh;
            if (eh == NULL) return oh;
            et->next = NULL;
            ot->next = eh;
            return oh;
        }
};