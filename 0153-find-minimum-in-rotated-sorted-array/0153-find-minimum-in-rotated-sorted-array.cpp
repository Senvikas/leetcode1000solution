class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0 , e = n-1;
        
        while(s < e){
            int mid = s + (e-s)/2;
            
            if(arr[s] < arr[e]) return arr[s];
            
            else if(arr[s] <= arr[mid]){
                s = mid+1;
            }else e = mid;
        }
        
        return arr[s];
    }
};