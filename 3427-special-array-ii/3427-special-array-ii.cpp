class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qs) {
        vector<int> index;
        int n = nums.size();

        bool prev = nums[0] & 1;   // odd

        for(int i=1; i<n; i++)
        {
            bool curr = nums[i] & 1;

            // parity is same
            if(prev == curr)
            {
                index.push_back(i-1);
            }

            prev = curr;
        }

        vector<bool> ans;
        for(auto q: qs)
        {
            int from = q[0], to = q[1];

            auto it = lower_bound(index.begin(), index.end(), from);
            if(it == index.end() || to <= *it)
            {
                ans.push_back(true);

            }
            else    
                ans.push_back(false);
        }

        return ans;
    }
};