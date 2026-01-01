class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        for (int i=digits.size()-1; i>=0; i--) {
            int val = (digits[i] + rem) % 10;
            digits[i] = val;
            if (!(rem = val == 0)) return digits;
        }
        if (rem) digits.insert(digits.begin(), rem);
        return digits;
    }
};