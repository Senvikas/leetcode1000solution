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
    int f(TreeNode* root)
    {
        if(!root) return 0;
        int left = f(root->left);
        int right = f(root -> right);
        
        int h = 1 + max(left, right);
        return h;
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};