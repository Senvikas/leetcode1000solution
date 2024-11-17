class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ps(n+1, 0);
        for(int i=0; i<n; i++)
        {
            ps[i+1] = ps[i] + nums[i];
        }

        int ml = n+1;
        deque<int> dq;

        for(int i=0; i<=n; i++)
        {
            while(!dq.empty() && ps[i] - ps[dq.front()] >= k)
            {
                ml = min(ml, i - dq.front());
                dq.pop_front();
            } 

            while(!dq.empty() && ps[i] <= ps[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ml <= n ? ml : -1;
    }
};