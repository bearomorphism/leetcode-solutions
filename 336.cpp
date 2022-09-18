struct TrieNode {
    TrieNode* next[26] = {};
    int index = -1;
    vector<int> palIndices;
};

class Solution {
private:
    TrieNode* root;
    void add(string &s, int i) {
        auto node = root;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (isPal(s, 0, j)) node->palIndices.push_back(i);
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palIndices.push_back(i);
    }
    bool isPal(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i >= j;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        int n = words.size();
        for (int i = 0; i < n; i++) {
            add(words[i], i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            auto s = words[i];
            auto cur = root;
            for (int j = 0; j < s.size() && cur; j++) {
                if (cur->index != -1 && cur->index != i && isPal(s, j, s.size() - 1))
                    ans.push_back({i, cur->index});
                cur = cur->next[s[j] - 'a'];
            }
            if (!cur) continue;
            for (int j: cur->palIndices) {
                if (i != j)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};