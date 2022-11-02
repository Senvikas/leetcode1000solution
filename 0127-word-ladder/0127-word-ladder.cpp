class Solution
{
    public:
        int ladderLength(string b, string e, vector<string> &wordList)
        {
            unordered_set<string> valid;
            for (auto &w: wordList)
                valid.insert(w);
            if (valid.find(e) == valid.end()) return 0;
            int n = b.length();

            int cnt = 1;
            queue<string> q;
            q.push(b);
            valid.erase(b);

           	//bfs
            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    string s = q.front();
                    q.pop();

                    for (int i = 0; i < n; i++)
                    {
                        for (char c = 'a'; c <= 'z'; c++)
                        {
                            string newword = s;
                            newword[i] = c;

                            if (newword == e)
                                return cnt + 1;
                            if (valid.find(newword) != valid.end())
                            {
                                q.push(newword);
                                valid.erase(newword);
                            }
                        }
                    }
                }
                cnt++;
            }
            return 0;
        }
};