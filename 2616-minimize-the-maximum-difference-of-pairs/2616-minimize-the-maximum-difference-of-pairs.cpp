class Solution {
public:
	int minimizeMax(vector<int>& a, int p) {
		sort(a.begin(), a.end());
		int s = 0, e = 1e9;
		while (s <= e) {
			int mid = (s + e) / 2;
			int count = 0;
			for (int i = 1; i < a.size(); i++) {
				if (a[i] - a[i - 1] <= mid) {
					count++;
					i++;
				}
			}
			if (count < p) s = mid + 1;
			else e = mid - 1;
		}
		return s;
	}
};