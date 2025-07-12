class Trie {
public:
    Trie* children[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class StreamChecker {
private:
    Trie* root;
    string stream;
    int maxLen;

public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        stream = "";
        maxLen = 0;
        for (string word : words) {
            maxLen = max(maxLen, (int)word.size());
            reverse(word.begin(), word.end());
            Trie* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) 
                    node->children[idx] = new Trie();
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    }

    bool query(char letter) {
        stream += letter;
        if (stream.size() > maxLen) 
            stream.erase(stream.begin()); // Keep buffer size <= maxLen

        Trie* node = root;
        for (int i = stream.size() - 1; i >= 0; i--) {
            int idx = stream[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
            if (node->isEnd) return true;
        }
        return false;
    }
};