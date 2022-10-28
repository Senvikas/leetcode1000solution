#include<bits/stdc++.h>
class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &s)
        {

            int n = s.size();
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