class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        HashMap<Character, Integer> charIndexMap = new HashMap<>();

        for (int right = 0; right < n; right++) {
            char currentChar = s.charAt(right);

            if (charIndexMap.containsKey(currentChar)) {
                // Move the left pointer to the right of the previous occurrence of the character
                left = Math.max(charIndexMap.get(currentChar) + 1, left);
            }

            // Update the character's last seen index
            charIndexMap.put(currentChar, right);

            // Update the maximum length of the substring
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }

}
