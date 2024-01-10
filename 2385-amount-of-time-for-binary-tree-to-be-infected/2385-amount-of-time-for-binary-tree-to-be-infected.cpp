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
    int result;
    int amountOfTime(TreeNode* root, int start) {
        DFS(root, start);
        return result;
    }
    int DFS(TreeNode* node, int start){
        if(node == NULL){
            return 0;
        }
        int leftDepth = DFS(node->left, start);
        int rightDepth = DFS(node->right, start);

        if(node->val == start){
            result = std::max(leftDepth, rightDepth);
            return -1;
        }
        else if(leftDepth >= 0 && rightDepth >= 0){
            return std::max(leftDepth, rightDepth)+1;
        }
        result = std::max(result, std::abs(leftDepth-rightDepth));
        return std::min(leftDepth, rightDepth)-1;
    }
};