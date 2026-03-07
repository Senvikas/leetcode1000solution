class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string s2 = s + s;

        // Build two alternating patterns of size 2n
        string alt1 = "", alt2 = "";
        for (int i = 0; i < 2 * n; ++i) {
            alt1 += (i % 2 == 0) ? '0' : '1';
            alt2 += (i % 2 == 0) ? '1' : '0';
        }

        int minFlip = INT_MAX;
        int diff1 = 0, diff2 = 0;

        for (int i = 0; i < 2 * n; ++i) {
            if (s2[i] != alt1[i]) diff1++;
            if (s2[i] != alt2[i]) diff2++;

            // shrink window when size > n
            if (i >= n) {
                if (s2[i - n] != alt1[i - n]) diff1--;
                if (s2[i - n] != alt2[i - n]) diff2--;
            }

            if (i >= n - 1) {
                minFlip = min({minFlip, diff1, diff2});
            }
        }

        return minFlip;
    }
};
