class Solution {
private:
    long long mod = 1e9+7;
    vector<string> columnStates;
    vector<vector<int>> dp;
    vector<vector<int>> compat;

    void getStates(vector<string> &res, string &state, string &colors) {
        if(state.size() == 3) {
            res.push_back(state);
            return;
        }
        for(char ch: colors) {
            if(state.empty() || state.back() != ch) {
                state.push_back(ch);
                getStates(res, state, colors);
                state.pop_back();
            }
        }
    }

    vector<string> getColumnStates() {
        string colors = "RGB";
        string state = "";
        vector<string> res;
        getStates(res, state, colors);
        return res;
    }

    bool checkStates(string &prevState, string &currState) {
        for(int i=0; i<3; i++) {
            if(prevState[i] == currState[i]) return false;
        }
        return true;
    }

    int findWaysMemo(int prevStateInd, int remInds) {
        if(remInds == 0) return 1;
        if(dp[prevStateInd][remInds] != -1) return dp[prevStateInd][remInds];

        long long ways = 0;
        for(int next : compat[prevStateInd]) {
            ways = (ways + findWaysMemo(next, remInds-1)) % mod;
        }
        return dp[prevStateInd][remInds] = (int)ways;
    }

public:
    int numOfWays(int n) {
        columnStates = getColumnStates();
        int m = columnStates.size();

        // Precompute compatibility
        compat.assign(m, {});
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                if(checkStates(columnStates[i], columnStates[j])) {
                    compat[i].push_back(j);
                }
            }
        }

        dp.assign(m, vector<int>(n, -1));

        long long ways = 0;
        for(int stateInd=0; stateInd<m; stateInd++) {
            ways = (ways + findWaysMemo(stateInd, n-1)) % mod;
        }
        return (int)ways;
    }
};
