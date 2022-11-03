class Solution
{
    int solve(vector<int> &arr, int s, int e)
    {
        if (s > e)
            return 0;
        //choose_first -> if opponent chooses end................if opponent choose start
        int choose_first = arr[s] + min(solve(arr, s + 1, e - 1), solve(arr, s + 2, e));
        int choose_last = arr[e] + min(solve(arr, s + 1, e - 1), solve(arr, s, e - 2));
        //choose-lase             if opponent chooses start      if he chooses last one

        return max(choose_first, choose_last);
    }

    public:
        bool PredictTheWinner(vector<int> &nums)
        {
            int n = nums.size();
            int sum = 0;
            for (int i = 0; i < n; i++) sum += nums[i];
            int bestScore = solve(nums, 0, n - 1);
            if (bestScore >= sum - bestScore)
                return true;
            return false;
        }
};