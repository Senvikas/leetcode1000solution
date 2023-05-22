
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        std::vector<std::pair<int, int>> freqPairs;
        for (auto& entry : frequency) {
            freqPairs.push_back(entry);
        }

        // Sort the frequency pairs based on the frequency in descending order
        std::sort(freqPairs.begin(), freqPairs.end(),
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                      return a.second > b.second;
                  });

        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqPairs[i].first);
        }

        return result;
    }
};

