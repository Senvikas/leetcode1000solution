class Solution {
    bool isPossible(long long mid , vector<int>arr , int n){
        long long count = 0;
        for(auto i : arr){
            if(i<=mid){
                count += i;
            }
            else count += mid;
        }
        count/=n;
        if(count >= mid){
            return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& arr) {
        long long s = 0;
        long long e = 0;
        long long ans = 0;
        for(int i =0 ;i<arr.size();i++){
            e += arr[i];
        }
        e = e/n;
        long long mid = s + (e-s)/2;
        while(s<=e){
            if(isPossible(mid,arr,n)){
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};