class Solution {
public:
    int binSearch(vector<int> &arr, int s, int e){
        int mid = s + (e-s)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])return mid;
        if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])return binSearch(arr, mid, e);
        return binSearch(arr, s, mid);
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = binSearch(arr, 0, arr.size());
        return ans;
    }
};