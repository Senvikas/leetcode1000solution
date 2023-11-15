class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = n, last = 0;
        for(int i=0;i<n;i++){
            if (arr[i] <= last){
                int posLastVal = i != n-1 ? last + 1: last;
                ans = min(ans, max(n-i, posLastVal));
            }else{
                last++;
            }
        }
        return ans;
    }
};