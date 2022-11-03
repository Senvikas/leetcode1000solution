class Solution
{
    void solve(vector<vector < int>> &ans, vector< int > &path, int boundary, int k, int ind)
    {
       	//base casse k-> target & boundary means numbers that sum up to target
        if (boundary < 0 || k < 0) return;
        if (boundary == 0 && k == 0)
        {
            ans.push_back(path);
            return;
        }
        for (int i = ind; i < 10; i++)
        {
            path.push_back(i);
            solve(ans, path, boundary - 1, k - i, i + 1);
            path.pop_back();
        }
        return;
    }

    public:
        vector<vector < int>> combinationSum3(int k, int n)
        {
            vector<vector < int>> ans;
            vector<int> path;
            solve(ans, path, k, n, 1);
            return ans;
        }
};