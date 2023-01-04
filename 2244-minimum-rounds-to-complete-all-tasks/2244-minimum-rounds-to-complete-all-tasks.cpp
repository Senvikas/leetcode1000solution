class Solution
{
    public:
        int rec(int num)
        {
            if (num == 1) return -1;
            if (num % 3 == 0) return num / 3;
            else return 1 + rec(num - 2);
        }
    int minimumRounds(vector<int> &tasks)
    {
        int round = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < tasks.size(); i++)
        {
            m[tasks[i]]++;
        }
        for (auto it: m)
        {
            int temp = rec(it.second);
            if (temp == -1) return -1;
            else round += temp;
        }
        return round;
    }
};