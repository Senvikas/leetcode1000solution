class Solution
{
    void solve(vector<vector < string>> &ans, vector< string > &path, string s, int size, int ind)
    {
        if (ind == size)
        {
            ans.push_back(path);
            return;
        }

        for (int i = ind; i < size; i++)
        {
            if (ispal(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                solve(ans, path, s, size, i + 1);
                path.pop_back();
            }
        }
    }

    bool ispal(string s, int st, int e)
    {
        while (st <= e)
        {
            if (s[st++] != s[e--]) return false;
        }
        return true;
    }

    public:
        vector<vector < string>> partition(string s)
        {
            int size = s.size();
            vector<vector < string>> ans;
            vector<string> path;
            solve(ans, path, s, size, 0);
            return ans;
        }
};