class Solution {
    bool check(vector<int> &w, int n, int days, int mid)
    {
        int ourdays = 1;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += w[i];
            
            if(sum > mid)
            {
                sum = w[i];
                ourdays++;
            }
        }
        return ourdays<=days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxwt = 0;
        for(int &wt : weights)
            maxwt += wt;
        int s = *max_element(weights.begin(), weights.end());
        int e = maxwt;
        int ans = 0;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(check(weights, n, days, mid))
            {
                ans = mid;
                e = mid - 1;
                    
            }
            else 
                s = mid + 1;
        }
        return ans;
    }
};