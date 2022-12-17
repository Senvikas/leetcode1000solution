class Solution
{
    public:
        int evalRPN(vector<string> &tokens)
        {
            if (tokens.empty()) return -1;
            stack < long long > s;
            for (int i = 0; i < tokens.size(); i++)
            {
                if (isNum(tokens[i]))
                {
                    s.push(stoll(tokens[i]));
                }
                else
                {
                    long long tmp1 = s.top();
                    s.pop();
                    long long tmp2 = s.top();
                    s.pop();
                    if (tokens[i] == "+")
                    {
                        s.push(tmp2 + tmp1);
                    }
                    else if (tokens[i] == "-")
                    {
                        s.push(tmp2 - tmp1);
                    }
                    else if (tokens[i] == "*")
                    {
                        s.push(tmp2 *tmp1);
                    }
                    else if (tokens[i] == "/")
                    {
                        s.push(tmp2 / tmp1);
                    }
                }
            }
            return s.top();
        }
    private:
        bool isNum(string s)
        {
            return s != "+" && s != "-" && s != "*" && s != "/";
        }
};