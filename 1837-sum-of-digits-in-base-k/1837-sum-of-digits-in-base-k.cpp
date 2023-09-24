class Solution {
public:
    int solve(int n, int k){
        if(n < k) return n;
        int rem = n%k;
        n /= k;
        return rem + solve(n, k);
    }
    int sumBase(int n, int k) {
        return solve(n, k);
    }
};