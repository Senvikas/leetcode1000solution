class Trie
{
    private:
        Trie *links[26] = { nullptr
        };
    bool isEnd = false;
    public:
        void insert(string & s)
        {
            Trie *te = this;
            for (auto &x: s)
            {
                if (te->links[x - 'a'] == nullptr) te->links[x - 'a'] = new Trie();
                te = te->links[x - 'a'];
            }
            te->isEnd = true;
        }
    int findEnds(string &s, int ind)
    {
        Trie *te = this;
        for (int i = ind; i < s.size(); i++)
        {
            if (te->links[s[i] - 'a'] == nullptr) return INT_MAX;
            if (te->links[s[i] - 'a']->isEnd)
            {
                int k = findEnds(s, i + 1);
                if (k != INT_MAX) return k + 1;
            }
            te = te->links[s[i] - 'a'];
        }
       	//If I reached this point because i have checked ther entrie string return 0, else I have reached here with no match return INT_MAX
        return ind == s.size() ? 0 : INT_MAX;
    }
};

class Solution
{
    public:
        vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
        {
            vector<string> ans;
           	//Create a Trie structure
            Trie *trie = new Trie();
           	//Insert all words into the Trie..
            for (auto &x: words)
                trie->insert(x);
           	//Checking for multiple ends in the Trie..
            for (auto &x: words)
                if (trie->findEnds(x, 0) >= 2) ans.push_back(x);
            return ans;
        }
};