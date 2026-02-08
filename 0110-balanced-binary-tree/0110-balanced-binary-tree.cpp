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
    int ans = true;
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        // cout << findH(root) << endl;
        findH(root);
        return ans;
    }

    int findH(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int lh = findH(root->left);
        int rh = findH(root->right);

        if(abs(rh - lh) > 1)
        {
            ans = false;
            return -1;
        }

        return max(lh, rh) + 1;
    }
};