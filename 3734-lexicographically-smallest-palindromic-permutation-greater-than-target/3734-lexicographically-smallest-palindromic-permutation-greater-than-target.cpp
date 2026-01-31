class Solution {
public:
    int odd;
    char mid;
    string res = "";

    bool solve(int ind, string &form, vector<int> &freq, string &s, string &t, bool flag)
    {
        // base: first half complete
        if(form.size() == t.size()/2)
        {
            string rev = form;
            reverse(rev.begin(), rev.end());

            string full = form;
            if(odd) full.push_back(mid);
            full += rev;

            if(full > t){
                res = full;
                return true;
            }
            return false;
        }

        for(int i=0;i<26;i++)
        {
            if(freq[i]==0) continue;

            // pruning using first-half lex compare
            if(!flag && char('a'+i) < t[ind]) continue;

            form.push_back('a'+i);
            freq[i]--;

            bool newFlag = flag;
            if(char('a'+i) > t[ind]) newFlag = true;

            if(solve(ind+1, form, freq, s, t, newFlag))
                return true;

            form.pop_back();
            freq[i]++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26,0);

        for(char ch: s)
            freq[ch-'a']++;

        odd = 0;
        mid = ' ';

        for(int i=0;i<26;i++){
            if(freq[i]&1){
                odd++;
                mid = char('a'+i);
            }
            freq[i] /= 2;   // keep only half
        }

        if(odd > 1) return "";

        string form="";
        solve(0, form, freq, s, target, false);

        return res;
    }
};