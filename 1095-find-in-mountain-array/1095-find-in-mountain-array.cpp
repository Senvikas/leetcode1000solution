/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int tar, MountainArray &mountainArr) {
        int len = mountainArr.length();
        
        // find the peak ele
        int l = 1, r = len-2; int mid = 0;
        
        while(l<=r){
            mid = (l+r)/2;
            
            int left = mountainArr.get(mid-1);
            int middle = mountainArr.get(mid);
            int right = mountainArr.get(mid+1);
            // in left portion
            if(left < middle && middle < right){
                l = mid+1;
            }else if(left > middle && middle > right){
                r = mid-1;
            }
            else break;
        }
        int peak = mid;
        //serch from left to peak
        l = 0; r = peak;
        while(l <= r){
            mid = (l+r)/2;
            int middle = mountainArr.get(mid);
            if(middle < tar) l = mid+1;
            else if(middle > tar) r = mid-1;
            else return mid;
        }
        //search from peak+1 to end
        l = peak+1, r = len-1;
        while(l <= r){
            mid = (l+r)/2;
            int middle = mountainArr.get(mid);
            if(middle > tar) l = mid+1;
            else if(middle < tar) r = mid-1;
            else return mid;
        }
        
        return -1;
    }
};