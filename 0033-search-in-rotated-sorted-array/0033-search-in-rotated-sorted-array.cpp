class Solution {
public:
    int pivot(vector<int> &arr, int n){
        for(int i=1; i<n-1; i++)
        {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                return i;
        }
        return 0;
    }
    
    int search(vector<int>& arr, int target) {
        //algo- 1. find pivot, 2. apply bs in both the part
        int n=arr.size();
        int pivot_index = pivot(arr, n);
        //cout<<pivot_index;
        //for first part 0-k
        int s=0, e=pivot_index;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] < target)
                s = mid+1;
            else
                e = mid-1;
        }
        //second part k+1, n
        s=pivot_index+1, e=n-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] < target)
                s = mid+1;
            else
                e = mid-1;
        }
        
        return -1;
    }
};