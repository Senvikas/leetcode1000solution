class Solution
{
    public:
        int evalRPN(vector<string> &tokens)
        {
            int n = tokens.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
               	//case 1-> operator
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
                {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    int computed = 0;
                    if (tokens[i] == "+") computed = a + b;
                    if (tokens[i] == "-") computed = a - b;
                    if (tokens[i] == "*") computed = a * b;
                    if (tokens[i] == "/") computed = a / b;

                    st.push(computed);
                }
                else
                    st.push(stoi(tokens[i]));
            }
            return st.top();	//since the given constraints shows that there will always exist an answer.
        }
};