class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first == b.first ? a.second < b.second : a.first<b.first;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<int> temp;
        vector<pair<int, int>> A;

        for (auto it : arr) {
            A.push_back({__builtin_popcount(it), it});
        }

        sort(A.begin(), A.end(), cmp);

        for (auto it : A) {
            temp.push_back(it.second);
        }

        return temp;
    }
};