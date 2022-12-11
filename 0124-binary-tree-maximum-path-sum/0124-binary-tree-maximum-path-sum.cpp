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
        int solve(TreeNode *root, int &ans)
        {
            if (!root) return 0;

            int ls = solve(root->left, ans);
            int rs = solve(root->right, ans);

            int path_sum = max(root->val, max(ls, rs) + root->val);
            int inc_root = max(path_sum, ls + rs + root->val);
            ans = max(ans, inc_root);
            return path_sum;
        }

    int maxPathSum(TreeNode *root)
    {

        int maxsum = INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
};