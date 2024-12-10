public class Solution {
    private bool FindTwice(string s, string special, int ind) {
        int cnt = 2;
        int n = s.Length;
        int len = special.Length;
        for (int j = ind; j <= n - len; j++) {
            string sub = s.Substring(j, len);
            if (sub == special) {
                cnt--;
                if (cnt == 0) return true;
            }
        }
        return false;
    }

    public int MaximumLength(string s) {
        int n = s.Length;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            string special = "";
            for (int j = i; j < n; j++) {
                if (special.Length > 0 && special[special.Length - 1] != s[j]) break;
                special += s[j];
                if (FindTwice(s, special, i + 1)) {
                    ans = Math.Max(ans, special.Length);
                }
            }
        }

        return ans;
    }
}
