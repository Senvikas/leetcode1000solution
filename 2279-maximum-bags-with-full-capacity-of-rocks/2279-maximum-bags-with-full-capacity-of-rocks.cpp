class Solution
{
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first - a.second < b.first - b.second;
    }
    public:
        int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
        {

            int n = capacity.size();
           	//otherwise use greedy:
            vector<pair<int, int>> capRoc;
            for (int i = 0; i < n; i++)
                capRoc.push_back({ capacity[i],
                    rocks[i] });

           	//now sort and put the least empty bag at first position
            sort(capRoc.begin(), capRoc.end(), cmp);
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                int diff = capRoc[i].first - capRoc[i].second;
                if (diff == 0 || diff <= additionalRocks)
                {
                    additionalRocks -= diff;
                    cnt++;
                }
                else break;
            }

            return cnt;
        }
};