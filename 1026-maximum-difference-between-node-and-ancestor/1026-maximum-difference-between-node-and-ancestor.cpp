/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int solve(TreeNode *root, int mini, int maxi)
        {
            if (root == nullptr) return maxi - mini;
            maxi = max(maxi, root->val);
            mini = min(mini, root->val);
            return max(solve(root->left, mini, maxi), solve(root->right, mini, maxi));
        }
    int maxAncestorDiff(TreeNode *root)
    {
        int mini = 100000, maxi = 0;
        return solve(root, mini, maxi);
    }
};