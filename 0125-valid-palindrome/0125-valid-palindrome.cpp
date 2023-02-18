class Solution {
public:
    bool f(int i, int j, string &s)
    {
        if(i>=j) return true;
        if(!isalpha(s[i])) return f(i+1, j, s);
        if(!isalpha(s[j])) return f(i, j-1, s);
        if(tolower(s[i]) == tolower(s[j])) return f(i+1, j-1, s);
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
