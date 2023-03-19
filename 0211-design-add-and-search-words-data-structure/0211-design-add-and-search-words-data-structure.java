class WordDictionary {
    TrieNode root;
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode curr = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word.charAt(i) - 'a';
            if(curr.child[idx] == null)
                curr.child[idx] = new TrieNode();
            curr = curr.child[idx];
        }
        curr.isEnd = true;
    }
    
    public boolean search(String word) {
        return f(0, word, root);
    }

    boolean f(int i, String s, TrieNode t){
        if(i == s.length())
            return t.isEnd;
        char ch = s.charAt(i);
        if(ch == '.'){
            for(int j = 0; j < 26; j++)
                if(t.child[j] != null && f(i + 1, s, t.child[j]))
                    return true;
        }
        else{
            int idx = ch - 'a';
            if(t.child[idx] == null)
                return false;
            else 
                return f(i + 1, s, t.child[idx]);
        }
        return false;
    }
}

class TrieNode{
    TrieNode child[] = new TrieNode[26];
    boolean isEnd;
}