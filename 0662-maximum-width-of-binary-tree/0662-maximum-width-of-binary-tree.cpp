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
        int widthOfBinaryTree(TreeNode *root)
        {

            int ans = 0;

            queue<pair<TreeNode*, long long int>> q;

            q.push({ root,
                1 });

            while (!q.empty())
            {

                int mx = 0;
                int mn = 0;
                int n = q.size();
                int first = q.front().second;

                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    long long int val = it.second - first;

                    q.pop();

                    if (i == 0)
                    {
                        mn = it.second;
                    }

                    if (i == n - 1)
                    {
                        mx = it.second;
                    }

                    if (it.first->left)
                    {
                        q.push({ it.first->left,
                            val *2 });
                    }

                    if (it.first->right)
                    {
                        q.push({ it.first->right,
                            val *2 + 1 });
                    }
                }

                ans = max(ans, mx - mn + 1);
            }

            return ans;
        }
};