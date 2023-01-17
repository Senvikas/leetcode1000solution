class Node
{
    Node *links[26];	// array to store the links to child nodes, one for each character of the english alphabet
    bool flag = false;	// flag to indicate end of a word
    public:
        bool containsKey(char ch)
        {
           	// checks if the current node has a link to the child node for the given character
            return (links[ch - 'a'] != NULL);	// 'a' is subtracted from the character to get the index of the array
        }

    void put(char ch, Node *node)
    {
       	// adds a link to the child node for the given character
        links[ch - 'a'] = node;	// 'a' is subtracted from the character to get the index of the array
    }

    Node* get(char ch)
    {
       	// returns the child node for the given character
        return links[ch - 'a'];	// 'a' is subtracted from the character to get the index of the array
    }

    void setEnd()
    {
       	// sets the end of word flag
        flag = true;
    }

    bool isEnd()
    {
       	// returns the end of word flag
        return flag;
    }
};

class Trie
{
    private:
        Node * root;	// root node of the trie
    public:
        Trie()
        {
           	// constructor to initialize the root node
            root = new Node();
        }

    void insert(string word)
    {
       	// adds a word to the trie
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i])) node->put(word[i], new Node());	// if the current node doesn't have a link to the child node for the current character, a new child node is added
            node = node->get(word[i]);	// traverses to the child node
        }
        node->setEnd();	// sets the end of word flag for the last node of the word
    }

    bool search(string word)
    {
       	// searches for a word in the trie
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i])) return 0;	// if a character of the word is not found in the trie, the word is not present
            node = node->get(word[i]);	// traverses to the child node
        }
        return node->isEnd();	// return true if the last node of the word has end of word flag set
    }

    bool startsWith(string word)
    {
       	// searches for a prefix in the trie
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i])) return 0;	// if a character of the word is not found in the trie, the prefix is not present
            node = node->get(word[i]);	// traverses to the child node
        }
        return true;	// if all the characters of the prefix are found in the trie, return true
    }
};