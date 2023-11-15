public class Solution {
    public String minWindow(String s, String t) {
        int m = s.length();
        int n = t.length();
        if (n > m) return "";
        String ans = "";

        HashMap<Character, Integer> mpt = new HashMap<>();
        HashMap<Character, Integer> mps = new HashMap<>();

        for (char ch : t.toCharArray()) {
            mpt.put(ch, mpt.getOrDefault(ch, 0) + 1);
        }

        int dMatchC = n, matchC = 0;
        int left = 0, minLen = Integer.MAX_VALUE;
        int minLeft = 0; // Keep track of the left index for the minimum window

        for (int right = 0; right < m; ++right) {
            char ch = s.charAt(right);

            if (mpt.containsKey(ch)) {
                mps.put(ch, mps.getOrDefault(ch, 0) + 1);
                if (mps.get(ch) <= mpt.get(ch)) {
                    matchC++;
                }
            }

            while (matchC == dMatchC) {
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minLeft = left;
                }

                char leftChar = s.charAt(left);
                if (mpt.containsKey(leftChar)) {
                    mps.put(leftChar, mps.get(leftChar) - 1);
                    if (mps.get(leftChar) < mpt.get(leftChar)) {
                        matchC--;
                    }
                }

                left++;
            }
        }

        if (minLen == Integer.MAX_VALUE) return ""; // No valid window found
        return s.substring(minLeft, minLeft + minLen);
    }
}
