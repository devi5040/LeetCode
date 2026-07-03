class Trie
{
public:
    struct TrieNode
    {
        TrieNode *children[26] = {};
        bool isEnd = false;
    };
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (!cur->children[i])
                cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    TrieNode *traverse(const string &s)
    {
        TrieNode *cur = root;
        for (char ch : s)
        {
            int i = ch - 'a';
            if (!cur->children[i])
                return nullptr;
            cur = cur->children[i];
        }
        return cur;
    }

    bool search(string word)
    {
        TrieNode *cur = traverse(word);
        return cur && cur->isEnd;
    }

    bool startsWith(string prefix)
    {
        return traverse(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */