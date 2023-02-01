class Solution
{
    public:
        string gcdOfStrings(string str1, string str2)
        {
            int n = str1.size(), m = str2.size();
            int gcd = __gcd(n, m);
            if (str1.substr(0, gcd) != str2.substr(0, gcd)) return "";
            int x = n / gcd, y = m / gcd;
            string temp = str1.substr(0, gcd);
            string a = "", b = "";
            for (int i = 0; i < x; i++) a += temp;
            for (int i = 0; i < y; i++) b += temp;
            return ((a == str1 && b == str2) ? str1.substr(0, gcd) : "");
        }
};