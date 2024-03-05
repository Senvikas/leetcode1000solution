class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;
        char ch = s[left];
        
        while (left < right && s[left] == s[right]) {
            ch = s[left];
            while (left < right && s[left] == ch) ++left;
            while (left <= right && s[right] == ch) --right;
        }
        
        return max(0, right - left + 1);
    }
};
