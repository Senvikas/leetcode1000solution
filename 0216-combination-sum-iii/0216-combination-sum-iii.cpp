class Solution
{
    private:
        void findCombinations(int k, int n, int prev, vector<int> path, vector<vector< int>> &ans)
        {
            if (n < 0)
                return;
            
            if (k == 0)
            {
                if (n == 0)
                    ans.push_back(path);
                path.clear();
                return;
            }

            for (int i = prev + 1; i < 10; i++)
            {
                if (i == prev) continue;

                if (i > n) break;
                path.push_back(i);
                findCombinations(k - 1, n - i, i, path, ans);
                path.pop_back();
            }
            return;
        }

    public:

        vector<vector < int>> combinationSum3(int k, int n)
        {
            vector<vector < int>> ans;
            vector<int> path;
            findCombinations(k, n, 0, path, ans);
            return ans;
        }
};