class Solution {
private:
    using ll = long long;
    ll comb(ll n, ll m, ll k) {
        ll res = 1;
        m = min(m, n - m);

        for (ll i = 1; i <= m; i++) {
            res = res * (n - i + 1) / i;
            if (res > k) {
                return k + 1;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, ll k) {
        int partition = s.length() / 2;
        vector<int> bucket(26, 0);

        for (int i = 0; i < partition; i++) {
            bucket[s[i] - 'a']++;
        }

        auto permutations = [&](int rem) {
            ll ways = 1;

            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) continue;

                ways *= comb(rem, bucket[i], k);

                if (ways > k) break;

                rem -= bucket[i];
            }

            return ways;
        };

        string left;
        ll startIndex = 1;

        for (int pos = 0; pos < partition; pos++) {
            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) continue;

                bucket[i]--;

                ll ways = permutations(partition - pos - 1);

                if (startIndex + ways > k) {
                    left += char(i + 'a');
                    break;
                }

                bucket[i]++;
                startIndex += ways;
            }
        }

        if (left.length() < partition) {
            return "";
        }

        string mid =
            (s.length() & 1) ? string(1, s[partition]) : "";

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};