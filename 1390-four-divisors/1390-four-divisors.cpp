class Solution {
public:
    void check(int num, int &ans)
    {
        int sum = num+1, cnt = 0;
        for(int n=2; n<=(num+1)/2; n++)
        {
            if(num%n == 0)
            {
                if(cnt == 2)
                { // gotten 2 already, this is 3rd.
                    return;
                }
                sum += n;
                cnt++;
            }
        }

        if(cnt != 2)
            return;   // got less then 2 divs.

        ans += sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int num: nums)
        {
            check(num, ans);
        }

        return ans;
    }
};