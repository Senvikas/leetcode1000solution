#define ll long long
ll mod = 1e9 + 7;

class Solution {
public:
    ll powExp(ll num, int power){
        if(power == 0) return 1;
        if(power == 1) return num;
        

        if(power & 1) return num * (powExp(num, power-1))%mod;
        return powExp((num%mod*num%mod)%mod, power/2)%mod;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        ll multi = multiplier;

        if(multi == 1) return nums;

        // Step 1: Prepare a set with (value, index) pairs
        set<pair<ll, int>> st;
        for (int i = 0; i < n; i++) {
            st.insert({(ll)nums[i], i});
        }

        // Step 2: Consume k until nums[min] * multi <= max(nums)
        while (k > 0) {
            auto itMini = st.begin();
            auto itMax = prev(st.end()); 

            ll mini = itMini->first, maxi = itMax->first;

            // If min * multiplier is greater than max, break
            if (mini * multi > maxi)
                break;

            ll value = (mini * multi)%mod ;  // % mod

            int index = itMini->second;

            // Remove the current minimum and insert the new modified value
            st.erase(itMini);
            st.insert({value, index});

            k--;
        }

        // cout << "after consuming first time: " << k << endl;

        // Step 3: Prepare a vector having set values
        vector<pair<ll, int>> setToVec(st.begin(), st.end());

        if (k >= n) {
            // cout << "K: " << k << endl;
            int timesK = k / n;
            cout << timesK << endl;
            for (int i = 0; i < n; i++) {
                ll mini = setToVec[i].first;
                int ind = setToVec[i].second;

                ll value = (mini%mod * powExp(multi, timesK))%mod;

                setToVec[i] = {value, ind};
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << setToVec[i].first << " ";
        // }
        // cout << endl;
        // Handle the remaining k
        int remK = k % n;
        for (int i = 0; i < remK; i++) {
            pair<ll, int> itMini = setToVec[i];
            ll mini = itMini.first;
            ll value = (mini * multi) % mod;

            setToVec[i] = {value, itMini.second};
        }

        // Step 4: Prepare the result vector with final values
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ll value = setToVec[i].first;
            int ind = setToVec[i].second;

            ans[ind] =
                (int)(value % mod); 
        }

        return ans;
    }
};
