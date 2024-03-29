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
        int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = 1 + max(left, right);
        return ans;
    }
    
    
    int fastdiameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int op1 = fastdiameterOfBinaryTree(root -> left);
        int op2 = fastdiameterOfBinaryTree(root -> right);
        
        int op3 = height(root->left) + height(root->right) +1;
        
        int ans = max(op1, max(op2, op3));
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return fastdiameterOfBinaryTree(root)-1;
    }
};