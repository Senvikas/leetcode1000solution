class Solution
{
    public:
        int subarraysDivByK(vector<int> &nums, int k)
        {
           	// Initialize variables for counting and prefix sum
            int n = nums.size(), cnt = 0, prefsum = 0;
           	// Create a prefix sum array with size of k
            vector<int> prefsumarr(k);
           	// Initialize the first element of prefix sum array to 1
            prefsumarr[prefsum]++;
           	// Iterate through the entire vector of integers
            for (int i = 0; i < n; i++)
            {
               	// Calculate the current prefix sum and take mod with k
                prefsum += nums[i];
                prefsum %= k;
               	// If prefix sum is negative, add k to make it positive
                if (prefsum < 0) prefsum += k;
               	// Add the frequency of the current prefix sum to the count
                cnt += prefsumarr[prefsum];
               	// Increment the frequency of the current prefix sum in the array
                prefsumarr[prefsum]++;
            }
            return cnt;
        }
};