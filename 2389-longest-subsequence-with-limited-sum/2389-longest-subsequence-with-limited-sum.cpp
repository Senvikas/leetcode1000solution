class Solution
{
    public:
        vector<int> answerQueries(vector<int> &arr, vector<int> &queries)
        {
            int n = arr.size();
            int m = queries.size();

            sort(arr.begin(), arr.end());
            int sum = 0;
            vector<int> pref_sum;

            for (int i = 0; i < n; i++)
            {
                sum += arr[i];
                pref_sum.push_back(sum);	// storing prefix sum
            }

            vector<int> ans(m, 0);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pref_sum[j] <= queries[i]) ans[i] = j + 1;	//updating max sum
                    else break;
                }
            }
            return ans;
        }
};