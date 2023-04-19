class Solution
{
    public:
        int ans = 0;
    int longestZigZag(TreeNode *root)
    {
        int l = helper(root->left, 0);
        int r = helper(root->right, 1);
        return max(ans, max(l, r));
    }

    int helper(TreeNode *root, bool right)
    {
        if (!root) return 0;

        int r = helper(root->right, 1);
        int l = helper(root->left, 0);

        if (right)
        {
            ans = max(ans, r);
            r = 1;
            l++;
        }
        else
        {
            ans = max(ans, l);
            l = 1;
            r++;
        }

        return max(l, r);
    }
};