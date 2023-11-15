class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> isPal(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            isPal[i][i] = 1;
            ans++;
        }

        // fill only the above half as it is not possible for a substring to start from the second char and end at the first.
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (len == 2) {
                    isPal[i][j] = (s[i] == s[j]);
                } else {
                    isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
                }

                if (isPal[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
