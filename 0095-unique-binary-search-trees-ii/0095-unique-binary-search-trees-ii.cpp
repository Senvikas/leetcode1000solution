class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            // If the tree is empty, create a new node with the given value
            return new TreeNode(val);
        }

        if (val < root->val) {
            // If the value is less than the current node's value, insert into the left subtree
            root->left = insertIntoBST(root->left, val);
        } else {
            // If the value is greater than or equal to the current node's value, insert into the right subtree
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};
