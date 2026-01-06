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

// Simple linked list node
struct BTSListNode {
    int val;
    BTSListNode* next;
    BTSListNode(int v) : val(v), next(nullptr) {}
};

class BSTIterator {
private:
    BTSListNode* head;   // head of linked list
    BTSListNode* curr;   // current pointer

    void inorder(TreeNode* root, BTSListNode*& tail) {
        if (!root) return;
        inorder(root->left, tail);
        // create new list node
        tail->next = new BTSListNode(root->val);
        tail = tail->next;
        inorder(root->right, tail);
    }

public:
    BSTIterator(TreeNode* root) {
        // dummy node to simplify list building
        BTSListNode* dummy = new BTSListNode(-1);
        BTSListNode* tail = dummy;
        inorder(root, tail);
        head = dummy->next;
        curr = head;
        delete dummy; // cleanup dummy
    }
    
    int next() {
        int val = curr->val;
        curr = curr->next;
        return val;
    }
    
    bool hasNext() {
        return curr != nullptr;
    }
};
