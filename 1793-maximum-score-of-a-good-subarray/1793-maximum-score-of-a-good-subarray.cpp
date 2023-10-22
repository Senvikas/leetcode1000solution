class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        int res = a[k];
        
        int i,j;
        i=j=k;
        int cur = a[k];
        
        while(i>=0 || j<n)
        {
            if(i==0 && j==n-1)
                break;
            int lv = i>0?a[i-1]:0;
            int rv = j<n-1?a[j+1]:0;
            if(lv>rv)
            {
                i--;
                cur = min(cur,lv);
            }
            else
            {
                j++;
                cur = min(cur,rv);
            }
            res = max(res,cur*(j-i+1));
        }
        
        return res;
    }
};