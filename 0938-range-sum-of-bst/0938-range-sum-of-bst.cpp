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
        int solve(TreeNode *root, int l, int h)
        {
            if (!root) return 0;
            int sum = 0;
            int val = root->val;
            sum += (val >= l && val <= h) ? val : 0;
            if (val >= l)
                sum += solve(root->left, l, h);
            if (val <= h)
                sum += solve(root->right, l, h);
            return sum;
        }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return solve(root, low, high);
    }
};