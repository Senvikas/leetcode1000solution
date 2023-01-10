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
private:
    bool isSame(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        bool left = isSame(p->left, q->left);
        bool right = isSame(p->right, q->right);
        
        bool value = p->val == q->val;
        
        if(left && right && value) return true;
        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);
    }
};