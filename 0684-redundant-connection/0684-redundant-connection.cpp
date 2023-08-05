class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, -1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int parent_u = find(parent, u);
            int parent_v = find(parent, v);

            if (parent_u == parent_v) {
                // If the nodes u and v already have the same parent,
                // it means the edge connecting them is redundant.
                return {u, v};
            } else {
                // Union the two components by setting their parent.
                parent[parent_u] = parent_v;
            }
        }

        return {}; // No redundant edge found.
    }

    int find(vector<int>& parent, int x) {
        if (parent[x] == -1) {
            return x;
        } else {
            parent[x] = find(parent, parent[x]);
            return parent[x];
        }
    }
};
