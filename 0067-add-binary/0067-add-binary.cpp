class Solution {
public:
    string addBinary(string a, string b)
    {
        while (a.length()!=b.length())
        {
            if (a.length()>b.length())
            {
                b="0"+b;
            }
            else
            {
                a="0"+a;
            }
        }
        int carry=0;
        string ans="";
        for(int i=a.size()-1;i>=0;i--){
            if (a[i]=='0' && b[i]=='0')
            {
                if (carry)
                {
                    ans="1"+ans;
                    carry=0;
                }
                else{
                    ans="0"+ans;
                }
            }
            else if (a[i]=='0' && b[i]=='1')
            {
                if (carry)
                {
                    ans="0"+ans;
                }
                else{
                    ans="1"+ans;
                }
            }
            else if (a[i]=='1' && b[i]=='0')
            {
                if (carry)
                {
                    ans="0"+ans;
                }
                else{
                    ans="1"+ans;
                }
            }
            else{
                if (carry)
                {
                    ans="1"+ans;
                }
                else{
                    ans="0"+ans;
                    carry=1;
                }
            }
        }
        if (carry)
        {
            return ("1"+ans);
        }
        return ans;
    }
};