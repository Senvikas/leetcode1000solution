class Solution {
public:
    int myAtoi(string s) {
        int ans  = 0;
        int sign = 1;
        int i = 0;

        int n = s.size();

        //step1 leading spaces ignored
        while(i<n && s[i] == ' ') i++;


        //now possiblities 1. digit-0, 2. other digits, 3 sign, 4. char
        if(i<n && s[i] == '-'){
            sign = -1; i++;
        }else if(i<n && s[i] == '+') i++;

        // digit-0, other digits, char
        while(i<n && s[i] == '0') i++;

        //other digits, char
        while(i<n && isdigit(s[i])){

            int val = s[i] - '0';
            if(INT_MAX/10 < ans || ans*10  > INT_MAX - val)
            return sign == 1 ? INT_MAX : INT_MIN;
            
            //cout << val << endl;
            ans = ans*10 + val;
            i++;
        }

        return ans*sign;

    }
};