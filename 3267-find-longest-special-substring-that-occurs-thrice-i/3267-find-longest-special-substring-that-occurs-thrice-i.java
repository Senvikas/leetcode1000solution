class Solution {
    private boolean findTwice(String s, String special, int ind) {
        int cnt = 2;
        int n = s.length();
        int len = special.length();
        for (int j = ind; j <= n - len; j++) {
            String sub = s.substring(j, j + len);
            if (special.equals(sub)) {
                cnt--;
                if (cnt == 0) return true;
            }
        }
        return false;
    }

    public int maximumLength(String s) {
        int n = s.length();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            StringBuilder special = new StringBuilder();
            for (int j = i; j < n; j++) {
                if (special.length() > 0 && special.charAt(special.length() - 1) != s.charAt(j))
                    break;
                special.append(s.charAt(j));
                if (findTwice(s, special.toString(), i + 1)) {
                    ans = Math.max(ans, special.length());
                }
            }
        }

        return ans;
    }
}
