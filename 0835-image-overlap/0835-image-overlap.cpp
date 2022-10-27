class Solution
{
    public:
        int largestOverlap(vector<vector < int>> &img1, vector< vector< int>> &img2)
        {
            int n = img1.size();
            vector<pair<int, int>> one1;
            vector<pair<int, int>> one2;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (img1[i][j] == 1)
                        one1.push_back({ i,j });
                    if (img2[i][j] == 1)
                        one2.push_back({ i,j });
                }
            }

            int ans = 0;
            map<pair<int, int>, int> mp;

            for (auto &a: one1)
            {
                for (auto &b: one2)
                {
                    mp[{(b.first) - a.first,(b.second) - a.second}]++;
                    ans = max(ans, mp[{b.first - a.first, b.second -a.second}]);
                }
            }
            return ans;
        }
};