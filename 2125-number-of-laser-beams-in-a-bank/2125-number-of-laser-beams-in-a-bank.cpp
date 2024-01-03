class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> count;
        int laser = 0;

        // Count lasers in each string
        for (int i = 0; i < bank.size(); i++) {
            for (auto &n : bank[i]) {
                if (n == '1') {
                    laser++;
                }
            }
            count.push_back(laser);
            laser = 0;
        }

        int beams = 0;
        int j = 0;
        int prevlaser;

        // Find the first non-zero laser count
        for (auto &i : count) {
            j++;
            if (i != 0) {
                prevlaser = i;
                break;  // Stop when the first non-zero laser count is found
            }
        }

        // Calculate beams based on subsequent non-zero laser counts
        for (int i = j; i < count.size(); i++) {
            if (count[i] != 0) {
                beams += count[i] * prevlaser;
                prevlaser = count[i];
            }
        }

        return beams;
    }
};