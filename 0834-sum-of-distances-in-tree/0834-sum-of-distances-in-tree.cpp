class Solution
{
    public:
        pair<int, int> sumOfDistancesInTree_(int idx, int cnt, int dist, vector<vector < int>> &conn, vector< int > &visited, vector< int > &res)
        {

            visited[idx] = true;
            int totalChildren = 0;
            int totalDist = 0;
            dist += cnt;

            for (int i = 0; i < conn[idx].size(); ++i)
            {
                if (visited[conn[idx][i]] == false)
                {

                    pair<int, int> tmp = sumOfDistancesInTree_(conn[idx][i], cnt + totalChildren, dist + totalDist + totalChildren, conn, visited, res);

                    totalChildren += tmp.first;
                    totalDist += tmp.second;
                }
            }

            res[idx] = totalDist + dist - cnt;

            return make_pair(totalChildren + 1, totalDist + totalChildren + 1);
        }

    pair<int, int> sumOfDistancesInTree_r(int idx, int cnt, int dist, vector<vector < int>> &conn, vector< int > &visited, vector< int > &res)
    {

        visited[idx] = true;

        res[idx] += dist;

        int totalChildren = 0;
        int totalDist = 0;
        dist += (cnt + 1);

        for (int i = conn[idx].size() - 1; i >= 0; --i)
        {
            if (visited[conn[idx][i]] == false)
            {

                pair<int, int> tmp = sumOfDistancesInTree_r(conn[idx][i], 1 + cnt + totalChildren, dist + totalDist + totalChildren, conn, visited, res);

                totalChildren += tmp.first;
                totalDist += tmp.second;
            }
        }

        return make_pair(totalChildren + 1, totalDist + totalChildren + 1);
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector < int>> &edges)
    {
        vector<int> res(N, 0);

        vector<vector < int>> conn(N);
        vector<int> visited(N, false);

        for (vector<int> &edge: edges)
        {
            conn[edge[0]].push_back(edge[1]);
            conn[edge[1]].push_back(edge[0]);
        }

        sumOfDistancesInTree_(0, 0, 0, conn, visited, res);

        visited = vector<int> (N, false);
        sumOfDistancesInTree_r(0, 0, 0, conn, visited, res);

        return res;
    }
};