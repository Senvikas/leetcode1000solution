class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> finalvec(m+n);
        for(int i=0; i<n; i++)
        {
            finalvec[i] = nums1[i];
        }
        for(int i=0; i<m; i++)
        {
            finalvec[i+n] = nums2[i];
        }
        sort(finalvec.begin(), finalvec.end());
        if((m+n)&1) return finalvec[(m+n)/2];
        return ( ((double)finalvec[(m+n)/2-1] + (double)finalvec[(m+n)/2])/2 );
        
    }
};