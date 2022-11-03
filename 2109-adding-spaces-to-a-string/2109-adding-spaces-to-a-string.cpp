class Solution
{
    public:
        string addSpaces(string s, vector<int> &spaces)
        {
            string ans = "";
            int n = s.length();
            int vn = spaces.size();
            int prev = 0;
            int end = 0;
            for (int i = 0; i < vn; i++)
            {
                end = spaces[i];
                string substring = s.substr(prev, end - prev);
                ans += substring;
                ans += " ";
                prev = end;
            }

            string substring = s.substr(prev);
            ans += substring;
            return ans;
        }
};