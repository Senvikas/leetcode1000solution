class Solution
{
    public:
        int ladderLength(string b, string e, vector<string> &wl)
        {
            unordered_set<string> st(wl.begin(), wl.end());
            unordered_set<string> vis;
            queue<string> q;
            if (st.find(e) == st.end()) return 0;
            int n = b.length();
            int cnt = 1;
            q.push(b);
            vis.insert(b);

            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    auto w = q.front();
                    q.pop();
                    for (int i = 0; i < n; i++)
                    {
                        for (char c = 'a'; c <= 'z'; c++)
                        {
                            auto nw = w;
                            nw[i] = c;
                            if (nw == e) return cnt + 1;
                            else if (st.find(nw) != st.end() && vis.find(nw) == vis.end())
                            {
                                vis.insert(nw);
                                q.push(nw);
                            }
                        }
                    }
                }
                cnt++;
            }
            return 0; //in case no possible ladder to rech from b to e.
        }
};