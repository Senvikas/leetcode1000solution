class Solution
{
    public:
        int minDeletionSize(vector<string> &strs)
        {
            int n = strs.size();
            int m = strs[0].size();
            vector<int> vis(m, 0);
            for (int i = 0; i < n - 1; i++)
            {
                auto s1 = strs[i];
                auto s2 = strs[i + 1];
                for (int j = 0; j < m; j++)
                {
                    if (s1[j] > s2[j])
                        vis[j] = 1;
                }
            }

            int ans = 0;
            for (auto i: vis)
                if (i) ans++;

            return ans;
        }
};