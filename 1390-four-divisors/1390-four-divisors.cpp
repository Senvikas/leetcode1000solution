class Solution {
public:
    bool isPrime(int num)
    {
        if(num < 2)
            return false;

        for(int d=2; d*d <= num; d++)
        {
            if(num%d == 0)
                return false;
        }

        return true;
    }

    int DivOf4(int num)
    {
        // case 1: 1 + p^3, p belongs to primes
        int root = round(pow(num, 1.0/3));
        if(root*root*root == num && isPrime(root))
        {
            int sum = 1 + root + root*root + num;
            return sum;
        }

        // case 2: 1 + p + q + pq, p,q belongs to primes
        // find p
        int p = -1;
        for(int d=2; d*d <= num; d++)
        {
            if(num%d == 0)
            {
                p = d;
                break;
            }
        }

        if(p == -1 || p*p == num)
            return 0;  // no divs || square

        int q = num/p;
        if(p*q == num && isPrime(p) && isPrime(q))
            return 1 + p + q + num;

        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int num: nums)
            ans += DivOf4(num);

        return ans;

    }
};