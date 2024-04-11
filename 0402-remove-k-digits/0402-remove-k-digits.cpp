class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string ans = "";
        for(char i : num)
        {
            while(ans.size() && k && ans.back() > i)
            {
                k--;
                ans.pop_back();
            }

            if(ans.size() || i != '0')
                ans.push_back(i);
        }

        while(ans.size() && k--)
            ans.pop_back();
        return ans.size() == 0 ? "0" : ans;
    }
};