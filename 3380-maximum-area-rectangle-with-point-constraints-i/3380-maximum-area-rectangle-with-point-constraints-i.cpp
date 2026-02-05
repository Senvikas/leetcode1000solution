class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        set<pair<int,int>> st;

        for (auto& p : points)
            st.insert({p[0], p[1]});

        int ans = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // must be diagonal
                if (x1 == x2 || y1 == y2) continue;

                // other two corners
                if (!st.count({x1, y2}) || !st.count({x2, y1}))
                    continue;

                // normalize rectangle
                int left = min(x1, x2);
                int right = max(x1, x2);
                int bottom = min(y1, y2);
                int top = max(y1, y2);

                bool ok = true;

                for (auto& p : points) {
                    int x = p[0], y = p[1];

                    // skip the four corners
                    if ((x == left && y == bottom) ||
                        (x == left && y == top) ||
                        (x == right && y == bottom) ||
                        (x == right && y == top))
                        continue;

                    // reject interior OR border points
                    if (x >= left && x <= right && y >= bottom && y <= top) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    int area = (right - left) * (top - bottom);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};
