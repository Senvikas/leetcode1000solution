class Solution {
public:
    static bool comp(string &s1, string &s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numsStr;
        for (int num : nums) {
            numsStr.push_back(to_string(num));
        }

        // Sort using the optimized comparator
        sort(numsStr.begin(), numsStr.end(), comp);

        // If the first string is "0", the entire result should be "0"
        if (numsStr[0] == "0") return "0";

        // Concatenate all sorted strings
        string ans;
        for (string &num : numsStr) {
            ans += num;
        }

        return ans;
    }
};
