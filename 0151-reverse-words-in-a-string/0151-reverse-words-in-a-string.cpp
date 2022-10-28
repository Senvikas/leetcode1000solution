/*
Qualcomm
Amazon
Microsoft
Cisco
Facebook
Twitter
*/
class Solution
{
    public:
        string reverseWords(string s)
        {
            if (s.size() == 0) return s;
            stack<string> stack;
            string result;
            string word = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ' && word.size() != 0)
                {
                    stack.push(word);
                    word.clear();
                }
                else if (s[i] == ' ' && word.size() == 0)	//skip spaces
                {
                    continue;
                }
                else
                {
                    word += s[i];
                }
            }
            cout << word.size() << endl;
            if (word.size() != 0)
                stack.push(word);
            while (!stack.empty())
            {
                result += stack.top();
                stack.pop();
                if (!stack.empty()) result += " ";
            }
            return result;
        }
};