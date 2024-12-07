class Solution {
public:
    bool tryBreaking(vector<int> &nums, int mxBalls, int tries)
    {
        for(int num: nums)
        {
            if(num < mxBalls)
                continue;

            if( (num/(tries + 1)) <= mxBalls )
            {
                int used = (num / mxBalls) - ((num % mxBalls == 0) ? 1 : 0);
                tries -= used;
            }

            else 
                return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            bool canBreak = tryBreaking(nums, mid, maxOperations);

            if(canBreak)
            {
                ans = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }


        return ans;
    }
};