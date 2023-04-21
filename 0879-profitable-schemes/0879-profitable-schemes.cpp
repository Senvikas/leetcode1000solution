class Solution
{
    public:
        int mod = 1e9 + 7;
    int cal(int i, int &minprofit, int &people, vector<int> &g, vector<int> &p, int profit, int pe, vector< vector< vector< long long>>> &dp)
    {

        if (pe > people)
            return 0;

        if (i == g.size())
        {
            if (pe <= people && profit >= minprofit)
                return 1;
            return 0;
        }
        if (profit >= minprofit)
        {
            profit = minprofit;
        }

        if (dp[i][pe][profit] != -1)
            return dp[i][pe][profit];

        int ans = 0;
       	// take
        ans = (ans + cal(i + 1, minprofit, people, g, p, profit + p[i], pe + g[i], dp)) % mod;
       	// nottake
        ans = (ans + cal(i + 1, minprofit, people, g, p, profit, pe, dp)) % mod;

        return dp[i][pe][profit] = ans % mod;
    }

    int profitableSchemes(int n, int mp, vector<int> &g, vector<int> &p)
    {

        vector<vector<vector< long long>>> dp(g.size() + 1, vector<vector < long long>> (101, vector < long long > (101, -1)));
        return cal(0, mp, n, g, p, 0, 0, dp);
    }
};