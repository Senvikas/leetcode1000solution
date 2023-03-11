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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* mid(ListNode* head)
    {
        ListNode *fast=head,*slow=head,*pre=NULL;
        while(fast&&fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(pre!=NULL)
        {
            pre->next=NULL;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* m=mid(head);
        TreeNode* tree=new TreeNode(m->val);
        if(head==m)
        {
            return tree;
        }
        tree->left=sortedListToBST(head);
        tree->right=sortedListToBST(m->next);
        return tree;
    }
};