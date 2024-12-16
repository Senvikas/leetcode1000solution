class Solution {
public:
    using p = pair<long long, int>;
    const long long mod = 1e9 + 7;

    // Modular exponentiation function
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        if(m == 1)
            return nums;
        priority_queue<p, vector<p>, greater<p>> pq; // Min-heap for smallest values
        int n = nums.size();
        long long maxi = INT_MIN;

        // Step 1: Initialize the priority queue and find the initial maximum
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            maxi = max(maxi, (long long)nums[i]);
        }

        // Step 2: Perform multiplications until min(nums) * m > max(nums)
        while (k > 0) {
            auto [val, ind] = pq.top();
            pq.pop();

            if (val * m > maxi) {
                // Break if min * m exceeds the current max value
                pq.push({val, ind});
                break;
            }

            val = (val % mod * m % mod) % mod; // Apply modulo after multiplication
            pq.push({val, ind});
            k--;
        }

        // Step 3: Handle remaining operations
        vector<p> cyclicBase;
        while (!pq.empty()) {
            cyclicBase.push_back(pq.top());
            pq.pop();
        }

        // If k is still greater than 0, calculate the cycle and distribute remaining operations
        if (k > 0) {
            int remK = k % n;         // Remaining operations that don't complete a cycle
            int cycleCount = k / n;  // Complete cycles for all elements

            // Update each element in the cyclic base
            for (auto& [val, ind] : cyclicBase) {
                // Apply `cycleCount` multiplications using modular exponentiation
                val = (val % mod * power(m, cycleCount)) % mod;
            }

            // Apply the remaining `remK` multiplications
            for (int i = 0; i < remK; i++) {
                cyclicBase[i].first = (cyclicBase[i].first % mod * m % mod) % mod;
            }
        }

        // Step 4: Reconstruct the final array from the cyclic base
        vector<int> result(n);
        for (auto [val, ind] : cyclicBase) {
            result[ind] = val % mod; // Ensure final modulo
        }

        return result;
    }
};
