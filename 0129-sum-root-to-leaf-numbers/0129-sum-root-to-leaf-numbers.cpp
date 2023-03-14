class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root)return 0;
        int res = 0;
        function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int sum) {
            if (!node->left && !node->right) {
                res += sum * 10 + node->val;
                return;
            }
            if (node->left)dfs(node->left, sum * 10 + node->val);
            if (node->right)dfs(node->right, sum * 10 + node->val);
        };
        dfs(root, 0);
        return res;
    }
};