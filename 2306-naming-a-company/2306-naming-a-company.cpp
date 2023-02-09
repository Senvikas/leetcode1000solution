class Solution
{
    public:
        long long distinctNames(vector<string> &ideas)
        {
            unordered_set<string> st(ideas.begin(), ideas.end());
            vector<vector < int>> dp(26, vector<int> (26, 0));

            for (int i = 0; i < ideas.size(); i++)
            {
                string cur = ideas[i];
                int ind = cur[0] - 'a';
                for (int j = 0; j < 26; j++)
                {

                    cur[0] = 'a' + j;

                    if (st.find(cur) == st.end()) dp[ind][j]++;
                }
            }

            long long count = 0;
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (i != j && dp[i][j] > 0) count += (dp[i][j] *dp[j][i]);
                }
            }

            return count;
        }
};