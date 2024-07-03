class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0, e = n-1, ans = INT_MAX;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(arr[s] <= arr[e]){   //means s to e sorted, hence arr[s] is the mini
                ans = min(ans, arr[s]);
                e = mid -1;
            }else{
                if(arr[s] <= arr[mid]){  //s to mid is sorted
                    ans = min(arr[s], ans);
                    s = mid+1;
                }else{
                    ans = min(ans, arr[mid]);
                    e = mid - 1;
                }
            }
        }
        
        return ans;
    }
};