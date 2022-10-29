class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        mp['I'] = 1;
        
        mp['V'] = 5;

        mp['X'] = 10;
        mp['L'] = 50;

        mp['C'] = 100;


        mp['D'] = 500;
        mp['M'] = 1000;
        reverse(s.begin(), s.end());
        int ans = mp[s[0]];
        int prev = ans;
        for(int i=1; i<n; i++)
        {
            int dig = mp[s[i]];
            if(dig < prev)
                ans -= dig;
            else
                ans += dig;
            prev = dig;   
            cout<<abs(ans)<<" ";
        }
        return abs(ans);
    }
};