/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

class Solution
{
    public:
        void ino(TreeNode *root, vector<int> &v)
        {
            if (!root) return;
            ino(root->left, v);
            if (!root->left && !root->right)
                v.push_back(root->val);
            ino(root->right, v);
            return;
        }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        ino(root1, v1);
        ino(root2, v2);

        return v1 == v2;
    }
};