class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;

    for (int i = 0; i < 30; ++i)
      res += ((c >> i) & 1) ? (((a >> i) & 1) | ((b >> i) & 1)) == 0 : ((a >> i) & 1) + ((b >> i) & 1);

    return res;
    }
};