class Solution {
public:
    int rotatedDigits(int n) {
        // Digits that are valid and can be rotated (0,1,8 are valid but must have at least one 2,5,6,9 to be "good")
        vector<int> valid = {0, 1, 2, 5, 6, 8, 9};
        unordered_map<int, int> rotate = {{0, 0}, {1, 1}, {2, 5}, {5, 2}, {6, 9}, {8, 8}, {9, 6}};
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            bool has_valid_rotation = false;
            int rotated_num = 0;
            int power = 1;
            bool is_good = true;
            
            while (num > 0) {
                int digit = num % 10;
                if (rotate.find(digit) == rotate.end()) { // Digit is invalid (3,4,7)
                    is_good = false;
                    break;
                }
                rotated_num += rotate[digit] * power;
                power *= 10;
                num /= 10;
            }
            
            if (is_good && rotated_num != i) {
                ans++;
            }
        }
        
        return ans;
    }
};