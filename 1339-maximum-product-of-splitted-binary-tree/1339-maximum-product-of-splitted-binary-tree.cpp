class Solution {
public:
    long long ans = 0, ts = 0;
    const int MOD = 1e9+7;

    // Compute total sum
    long long addition(TreeNode* root) {
        if(!root) return 0;
        return root->val + addition(root->left) + addition(root->right);
    }

    // DFS to compute subtree sums and update max product
    long long solve(TreeNode* root) {
        if(!root) return 0;
        long long left = solve(root->left);
        long long right = solve(root->right);
        long long subSum = root->val + left + right;

        // product if we cut here
        ans = max(ans, subSum * (ts - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        ts = addition(root);       // total sum
        solve(root);               // compute max product
        return ans % MOD;
    }
};
