class Solution
{
    public:
        int findMinArrowShots(vector<vector < int>> &points)
        {
            sort(points.begin(), points.end());

            int l = points[0][0], h = points[0][1];
            int cnt = 1;

            for (int i = 1; i < points.size(); i++)
            {
                if (points[i][0] >= l && points[i][0] <= h)
                {
                    l = points[i][0];
                    h = min(h, points[i][1]);
                }
                else
                {
                    cnt++;
                    l = points[i][0];
                    h = points[i][1];
                }
            }
            return cnt;
        }
};