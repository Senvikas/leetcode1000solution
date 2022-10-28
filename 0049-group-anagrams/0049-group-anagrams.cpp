#include<bits/stdc++.h>
class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &s)
        {

            int n = s.size();
            vector<pair<int,string> >vn;
            for (int i = 0; i < n; i++)
            {
                vn.push_back({ s[i].length(), s[i] });
            }

            sort(vn.begin(), vn.end());
            
            for(int i = 0; i<n; i++)
            cout<<vn[i].second<<" ";
            cout<<endl;
            
            
            map< vector<char>, vector<string> >mp;
            vector<vector < string>> ans;
            
            for (string &word: s)
            {
                int len = word.size();
                //make the freq vector for individual word
                vector<char> f(26, 0);
                for (int i = 0; i < len; i++)
                {
                    f[word[i]-'a']++;
                }
                //put this into the map
                mp[f].push_back(word);

            }
            for(auto &vectors : mp)
            {
                ans.push_back(vectors.second);
            }

            return ans;
        }
};