class Solution
{
    public:
        int ladderLength(string b, string e, vector<string> &l)
        {
            unordered_set<string> given(l.begin(), l.end());

            int n = b.length();
            queue<pair<string, int>> q;
            q.push({ b,
                1 });
            given.erase(b);

            while (!q.empty())
            {
                auto word = q.front().first;
                int steps = q.front().second;
                q.pop();
                if (word == e) return steps;

                for (int i = 0; i < n; i++)
                {
                    char original = word[i];
                    for (auto c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;

                        if (given.find(word) != given.end())
                        {
                            given.erase(word);
                            q.push({ word,
                                steps + 1 });
                        }
                    }
                    word[i] = original;
                }
            }

            return 0;
        }
};