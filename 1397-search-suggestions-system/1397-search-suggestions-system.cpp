
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        word = "";
    }
};

class Solution {
public:
    TrieNode* root;

    void insert(string& product) {
        TrieNode* node = root;
        for (char c : product) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
        node->word = product;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        // Sort products lexicographically
        sort(products.begin(), products.end());
        // Insert all products into the trie
        for (string& prod : products) {
            insert(prod);
        }

        vector<vector<string>> ans;
        TrieNode* node = root;
        bool noMatch = false;

        for (char c : searchWord) {
            if (noMatch) {
                ans.push_back({});
                continue;
            }
            int idx = c - 'a';
            if (!node->children[idx]) {
                noMatch = true;
                ans.push_back({});
                continue;
            }
            node = node->children[idx];
            vector<string> suggestions;
            dfs(node, suggestions);
            ans.push_back(suggestions);
        }
        return ans;
    }

    void dfs(TrieNode* node, vector<string>& suggestions) {
        if (suggestions.size() == 3) return;
        if (node->isEnd) {
            suggestions.push_back(node->word);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                dfs(node->children[i], suggestions);
                // if (suggestions.size() == 3) return;
            }
        }
    }
};