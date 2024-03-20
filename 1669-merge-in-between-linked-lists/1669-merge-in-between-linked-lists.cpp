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
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int indexA = 1;
        int indexB = 0;
        ListNode* temp1 = list1;

        while(indexA < a)
        {
            temp1 = temp1->next;
            indexA++;
        }
        ListNode* temp2 = list1;
        while(indexB <= b )
        {
            temp2 = temp2->next;
            indexB++;
        }
        temp1->next = list2;
        ListNode* temp3  =list2;
        while(temp3->next != NULL)
        {
            temp3 = temp3->next;
        }
        temp3->next = temp2;
        return list1;


    }
};