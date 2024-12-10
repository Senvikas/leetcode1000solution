class Solution {
public:
    bool findTwice(string &s, string &special, int ind)
    {
        int cnt = 2;
        int n = s.size();
        int len = special.size();
        for(int j=ind; j<=n-len; j++)
        {
            string sub = s.substr(j, len);
            if(special == sub)
            {
                cnt--;
                if(cnt == 0)
                    return true;
            }
        }
        return false;
    }

    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            string special = "";
            for(int j=i; j<n; j++)
            {
                if(special.empty() == false && special.back() != s[j])
                    break;
                special.push_back(s[j]);

                if(findTwice(s, special, i+1))
                {
                    ans = max(ans, (int)special.size());
                }
            }
        }

        return ans;
    }
};