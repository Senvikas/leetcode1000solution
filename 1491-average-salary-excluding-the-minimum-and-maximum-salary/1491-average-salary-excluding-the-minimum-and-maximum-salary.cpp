class Solution
{
    public:
        double average(vector<int> &salary)
        {
            int maxm = INT_MIN;
            int minm = INT_MAX;
            int sum = 0;
            int len = salary.size();
            for (int i = 0; i < len; i++)
            {
                sum += salary[i];
                maxm = max(maxm, salary[i]);
                minm = min(minm, salary[i]);
            }

            sum = sum - (minm + maxm);

            return (double)(sum) / (len - 2);
        }
};