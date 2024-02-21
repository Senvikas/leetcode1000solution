class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int lastSetbit = 0;
        int n = left;
        while(n){
            lastSetbit++;
           n = n >> 1;
        }
        
        
        long long ans = left;
        for(long long i=left; i<=(1<<lastSetbit) && (i<=right) ; i++)
        {
            ans = ans&i;
            if(ans == 0) return ans;
        }
        
        return (int)ans;
    }
};