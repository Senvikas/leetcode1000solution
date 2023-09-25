class Solution {
public:
    void solve(vector<int> &candi, vector<vector<int>> &ans, vector<int> &tmp, int t, int ind) {
        if (t == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int i = ind; i < candi.size() && t >= candi[i]; ++i) {
            if (i == ind || candi[i] != candi[i - 1]) { // Skip duplicates
                tmp.push_back(candi[i]);
                solve(candi, ans, tmp, t - candi[i], i + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candi, int t) {
        sort(candi.begin(), candi.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(candi, ans, tmp, t, 0);
        return ans;
    }
};
