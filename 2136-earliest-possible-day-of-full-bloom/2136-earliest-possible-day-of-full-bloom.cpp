class Solution
{
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    public:
        int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
        {
            int n = plantTime.size();
            vector<pair<int, int>> Time;

            for (int i = 0; i < n; i++)
                Time.push_back({ plantTime[i], growTime[i] });

           	//sort it
            sort(Time.begin(), Time.end(), cmp);

           	//compute the ans by planting first the seed with max grwoTime
            int s = 0, ans = 0;
            for (auto &p: Time)
            {
                s += p.first;
                ans = max(ans, s + p.second);
            }
            return ans;
        }
};