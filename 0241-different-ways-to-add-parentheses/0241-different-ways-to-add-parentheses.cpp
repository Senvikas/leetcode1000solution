class Solution
{
    vector<int> solve(string s)
    {
        vector<int> ans;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+' || s[i] == '*' || s[i] == '-')
            {
                vector<int> ans1 = solve(s.substr(0, i));
                vector<int> ans2 = solve(s.substr(i + 1));

                for (int j = 0; j < ans1.size(); j++)
                {
                    for (int k = 0; k < ans2.size(); k++)
                    {
                        if (s[i] == '-') ans.push_back(ans1[j] - ans2[k]);
                        else if (s[i] == '+') ans.push_back(ans1[j] + ans2[k]);
                        else ans.push_back(ans1[j] *ans2[k]);
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(s));
        return ans;
    }
    public:
        vector<int> diffWaysToCompute(string expression)
        {
            return solve(expression);
        }
};