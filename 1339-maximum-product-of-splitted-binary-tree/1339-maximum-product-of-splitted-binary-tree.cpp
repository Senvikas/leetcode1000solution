/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
long long mod = 1e9 + 7;
class Solution
{
    public:

        int minAbsDiff(TreeNode *root, int ts, int &diff, pair<int, int> &nums)
        {
            if (!root) return 0;

            int left_ans = minAbsDiff(root->left, ts, diff, nums);
            int right_ans = minAbsDiff(root->right, ts, diff, nums);

            int child = root->val + left_ans + right_ans;
            int num = ts - child;
            int thisDiff = abs(child - num);
            if (thisDiff < diff)
            {
                nums = make_pair(child, num);
                diff = thisDiff;
            }
            return child;
        }

    int add(TreeNode *root)
    {
        if (!root) return 0;
        int sum = 0;
        int left = add(root->left);
        int right = add(root->right);

        sum = root->val + left + right;
        return sum;
    }

    int maxProduct(TreeNode *root)
    {
       	//find total sum and check for every root that if this root got separated then what will be the ans_>>> this approach either give int overflow or wrong ans
       	//approach 2 -> find two such numbers who's abs diff is minimum
        int totalsum = add(root);

        int diff = totalsum;
        pair<int, int> nums = { 0,
            0
        };
        minAbsDiff(root, totalsum, diff, nums);
        long long ans;
        ans = (nums.first%mod *nums.second%mod) % mod;
        return int(ans);
    }
};