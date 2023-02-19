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
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {

            vector<vector < int>> res;
            if (root == NULL) return res;
            queue<TreeNode*> q;

            q.push(root);
            bool l_to_r = true;
            while (!q.empty())
            {
                int size = q.size();
                vector<int> ans(size);
               	//level process
                for (int i = 0; i < size; i++)
                {
                    auto frontnode = q.front();
                    q.pop();
                    int index = l_to_r ? i : size - i - 1;
                    ans[index] = frontnode->val;

                    if (frontnode->left) q.push(frontnode->left);
                    if (frontnode->right) q.push(frontnode->right);
                }
               	//change direction
                l_to_r = !l_to_r;
                res.push_back(ans);
            }
            return res;
        }
};