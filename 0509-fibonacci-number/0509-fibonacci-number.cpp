class Solution {
public:
    int f(int n){
        if(n<=1) return n;
        return f(n-2) + f(n-1);
    }
    int fib(int n) {
        //return f(n);
        if(n<=1) return n;
        int prev2 = 0;
        int prev1 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};