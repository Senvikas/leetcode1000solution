class Solution
{
    public:
        int maxRotateFunction(vector<int> &nums)
        {
            int n = nums.size();
            /*
            nums.resize(2*n);
            for(int i=n; i<2*n; i++)
            {
                nums[i] = nums[i%n];
            }
            cout << nums.size() <<endl;
            int ans = INT_MIN;
            for(int i=0; i < n; i++)
            {
                int len = i+n;
                int tmp = 0;
                for(int j=i; j < len; j++)
                {
                    tmp += nums[j]*(j-i);
                }
                ans = max(ans, tmp);
            }
            return ans;
            */	// N*N solution;
            /***N*1 **/
            int total = 0;
            for (auto &x: nums) total += x;

            int ans = INT_MIN;
            int tmp = 0;
            for (int i = 0; i < n; i++) tmp += nums[i] *i;

            for (int i = n - 1; i >= 0; i--)
            {
                tmp += total - n *nums[i];
                ans = max(ans, tmp);
            }
            return ans;
        }
};