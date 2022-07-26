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

class WordDictionary
{
private:
  TrieNode *root;
  bool dfs(string &word, int idx, TrieNode *cur)
  {
    if (!cur) return false;
    if (idx == word.length()) return cur->isEnd;
    if (word[idx] == '.')
    {
      for (int i = 0; i < 26; i++)
      {
        if (dfs(word, idx + 1, cur->children[i]))
          return true;
      }
      return false;
    }
    int j = word[idx] - 'a';
    return dfs(word, idx + 1, cur->children[j]);
  }

public:
  WordDictionary()
  {
    root = new TrieNode();
  }

  void addWord(string word)
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
    return dfs(word, 0, root);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */