class Solution {
public:

   int dfs(vector<int>& nums,vector<vector<int>>&comb) {
            int n = nums.size(),md=1e9+7;
            if (n <= 2) return 1;
            vector<int> left, right;
            for (int i = 1; i < n; ++i) {
                if (nums[i] < nums[0]) left.push_back(nums[i]);
                else right.push_back(nums[i]);
            }
            long long res = comb[n - 1][left.size()];
            res = res * dfs(left,comb) % md;
            res = res * dfs(right,comb) % md;
            return (int)res;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        int md=1e9+7;
        vector<vector<int>> comb(n + 1, vector<int>(n + 1));
        comb[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j]) % md;
            }
        }
        
        return dfs(nums,comb) - 1;
    }
};