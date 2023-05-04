class Solution
{
    public:
        string predictPartyVictory(string senate)
        {
            int n = senate.size();
            queue<int> q1, q2;
            for (int i = 0; i < n; i++)
            {
                (senate[i] == 'R') ? q1.push(i): q2.push(i);
            }
            while (!q1.empty() && !q2.empty())
            {
                int rad = q1.front(), dir = q2.front();
                (rad < dir) ? q1.push(rad + n): q2.push(dir + n);
                q1.pop(), q2.pop();
            }
            return (q1.size() > q2.size()) ? "Radiant" : "Dire";
        }
};