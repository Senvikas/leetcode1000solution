class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& qn) {
        vector<bool> ans;

        vector<int> parent(n), rnk(n, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> findPar = [&](int u){
            return parent[u]==u ? u : parent[u]=findPar(parent[u]);
        };

        function<void(int,int)> attach = [&](int u, int v){
            u = findPar(u); v = findPar(v);
            if (u == v) return;
            if (rnk[u] < rnk[v]) swap(u, v);
            parent[v] = u;
            if (rnk[u] == rnk[v]) ++rnk[u];
        };

        // Build components once: sort by value and union consecutive if gap <= maxDiff
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b){ return nums[a] < nums[b]; });
        for (int i = 1; i < n; ++i) {
            if (nums[ord[i]] - nums[ord[i-1]] <= maxDiff) {
                attach(ord[i], ord[i-1]);
            }
        }

        // Answer queries
        for (auto &q : qn) {
            int u = q[0], v = q[1];
            ans.push_back(findPar(u) == findPar(v));
        }
        return ans;
    }
};
