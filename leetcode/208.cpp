struct TrieNode
{
  vector<TrieNode *> children;
  bool isEnd;
  TrieNode()
  {
    children = vector<TrieNode *>(26, nullptr);
    isEnd = false;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }

  void insert(string word)
  {
    auto cur = root;
    for (char c : word)
    {
      int i = c - 'a';
      if (!cur->children[i])
        cur->children[i] = new TrieNode();
      cur = cur->children[i];
    }
    cur->isEnd = true;
  }

  bool search(string word)
  {
    auto cur = root;
    for (char c : word)
    {
      int i = c - 'a';
      if (!cur->children[i])
        return false;
      cur = cur->children[i];
    }
    return cur->isEnd;
  }

  bool startsWith(string prefix)
  {
    auto cur = root;
    for (char c : prefix)
    {
      int i = c - 'a';
      if (!cur->children[i])
        return false;
      cur = cur->children[i];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */