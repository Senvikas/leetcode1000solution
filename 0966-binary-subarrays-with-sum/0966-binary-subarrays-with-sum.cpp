#include <unordered_map>
#include <vector>

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        unordered_map<int, int> sumMap;
        int currentSum = 0;
        int count = 0;

        // Initialize the map with a base case: a cumulative sum of 0 has been seen once
        sumMap[0] = 1;

        for(int num : nums) {
            currentSum += num;

            // Check if there's a subarray that ends at the current position and sums to `goal`
            if(sumMap.find(currentSum - goal) != sumMap.end()) {
                count += sumMap[currentSum - goal];
            }

            // Update the map with the current cumulative sum
            sumMap[currentSum]++;
        }

        return count;
    }
};
