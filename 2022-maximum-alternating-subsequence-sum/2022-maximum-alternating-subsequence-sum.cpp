class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;
        for (int num : nums) {
            long long new_even = max(even, odd + num);     // we "add" this num
            long long new_odd = max(odd, even - num);      // we "subtract" this num
            even = new_even;
            odd = new_odd;
        }
        return even;  // always ends on even position
    }
};
