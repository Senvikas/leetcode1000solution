class Solution {
    vector<vector<int>> dp;
    int n;
    int m;
    int optimize(vector<int>& cuts, int i, int j)
    {
        if (i>=j-1) {dp[i][j] = 0; return 0;}
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int x = cuts[j]-cuts[i];
        for(int k=i+1; k<j; k++)
        {
            // cout << cuts[j] << " - "  << cuts[i] << "= " << x << endl;
            dp[i][j] = min(dp[i][j], x + optimize(cuts, k, j) + optimize(cuts, i, k));
        }
        return dp[i][j];
    }
public:
    int minCost(int n_, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n_);
        int n = n_;
        int m = cuts.size();
        dp.resize(m+1,vector<int>(m+1,INT_MAX));
        sort(cuts.begin(),cuts.end());
        return(optimize(cuts,0,m-1));
    }
};