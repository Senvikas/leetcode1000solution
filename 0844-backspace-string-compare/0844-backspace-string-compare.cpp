class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;

        for(auto ch: s)
        {
            if(ch!='#')
            st1.push(ch);
            else if(!st1.empty())
            st1.pop();
        }
        for(auto ch: t)
        {
            if(ch!='#')
            st2.push(ch);
            else if(!st2.empty())
            st2.pop();
        }

        string s1="";
        string s2="";
        while(!st1.empty())
        {
            s1+=st1.top();
            st1.pop();
        }
        while(!st2.empty())
        {
            s2+=st2.top();
            st2.pop();
        }

        return s1==s2;
    }
};