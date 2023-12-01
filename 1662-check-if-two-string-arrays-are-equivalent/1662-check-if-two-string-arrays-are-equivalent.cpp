class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        while (i1 < w1.size() && j1 < w2.size()) {
            if (w1[i1][i2] != w2[j1][j2])
                return false;
            i2++;
            j2++;
            if (i2 == w1[i1].length()) {
                i2 = 0;
                i1++;
            }
            if (j2 == w2[j1].length()) {
                j2 = 0;
                j1++;
            }
        }
        return i1 == w1.size() && j1 == w2.size() && i2 == 0 && j2 == 0;
    }
};