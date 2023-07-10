

class Solution {
public:
    int solve(TreeNode* root, int d){
        if (!root) return INT_MAX; // Return special value for empty subtree
        if (!root->left && !root->right) return d; // Leaf node
        
        int left = solve(root->left, d + 1);
        int right = solve(root->right, d + 1);
        
        // Exclude special values from the minimum calculation
        if (left != INT_MAX && right != INT_MAX)
            return min(left, right);
        else if (left != INT_MAX)
            return left;
        else
            return right;
    }
    
    int minDepth(TreeNode* root) {
        if (!root) return 0; // Handle case when root is NULL
        return solve(root, 1); // Start with depth 1 for the root node
    }
};
