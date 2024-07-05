class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int e = arr.back();
        int n = arr.size();
        int missNs = e - n;
        if(k > missNs){
            return e + k - missNs;
        }
        e = n;
        int s = 0;
        while(s<e){
            int mid = s + (e-s)/2;
            int missing = arr[mid] - mid - 1;
            if(missing < k) s = mid + 1;
            else e = mid;
        }
        return s + k;
    }
};