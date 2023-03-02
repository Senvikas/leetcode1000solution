class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>res;
        string ans = "";
        int n = chars.size();
        int cnt = 1;
        for(int i=1; i<n; i++)
        {
            if(chars[i] == chars[i-1])
                cnt++;
            else{
                if(cnt == 1) {res.push_back(chars[i-1]); ans += "@";}
                else{
                    int num = cnt;
                    cnt = 1;
                    res.push_back(chars[i-1]);
                    ans += "@";
                    vector<int> rev;
                    while(num)
                    {
                        int ld = num%10;
                        char ch = static_cast<char>(ld + '0');
                        cout << ch << endl;
                        rev.push_back(ch);
                        ans += "@";
                        num /= 10;
                    }
                    reverse(rev.begin(), rev.end());
                    res.insert(res.end(), rev.begin(), rev.end());
                }
            }
        }
        //cout << "size: " << res.size() << endl;
        if(cnt == 1) {ans += "@"; res.push_back(chars.back());}
        else{
               int num = cnt;
                    cnt = 1;
                    res.push_back(chars.back()); ans += "@";
                    vector<char> rev;
                    while(num)
                    {
                        int ld = num%10;
                        char ch = static_cast<char>(ld + '0');
                        cout << ch << endl;
                        rev.push_back(ch);
                        ans += "@";
                        num /= 10;
                    }
            reverse(rev.begin(), rev.end());
            res.insert(res.end(), rev.begin(), rev.end());
                }     
        //cout << "size: " << res.size() << endl;
        
        swap(chars, res);
        //cout << "size: " << chars.size() << endl;
        return ans.size();
    }
};