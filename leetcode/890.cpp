class Solution
{
private:
  string getPattern(string word) {
    vector<int> v(26, -1);
    string ret;
    int x = 0;
    for (char c: word) {
      if (v[c - 'a'] == -1) {
        v[c - 'a'] = x++;
      }
      ret.push_back(v[c - 'a'] + 'a');
    }
    return ret;
  }
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern)
  {
    string normalized = getPattern(pattern);
    vector<string> ret;
    for (auto w: words) {
      if (normalized == getPattern(w)) {
        ret.push_back(w);
      }
    }
    return ret;
  }
};