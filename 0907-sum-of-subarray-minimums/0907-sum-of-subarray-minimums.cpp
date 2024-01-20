class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;

        // Find the nearest smaller element on the left for each element
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[i] < arr[s1.top()]) {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        // Find the nearest smaller element on the right for each element
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[i] <= arr[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        // Calculate the sum of subarray mins
            int result = 0;
            for (int i = 0; i < n; ++i) {
                // Use long long to prevent integer overflow
                result = (result + (static_cast<long long>(arr[i]) * (i - left[i]) * (right[i] - i)) % MOD) % MOD;
            }

            // Ensure result is non-negative
            result = (result + MOD) % MOD;
        return result;

    }
};


