class Solution {
public:
    int countHomogenous(string s) {
        int m = 1e9+7;
        int n = s.size(); cout<<n<<endl;
        vector<int>suff(n, 0);
        suff[0] = 1;
        int ans = 01;
        for(int i=1; i<n; i++)
        {
            suff[i] = 1;
            if(s[i] == s[i-1])
                suff[i] = (suff[i] + suff[i-1])%m;
            ans = (ans + suff[i])%m;
        }
        return ans%m;
    }
};