class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> vis(wordList.begin(), wordList.end());
        vector<string> v1{beginWord}, v2;
        int result = 1;
        while (!v1.empty()) {
            v2.clear();
            result++;
            for (auto &word: v1) { // L times visit in
                for (int i = 0; i < word.length(); i++) { // at most 10 times
                    char tmp = word[i];
                    for (char c = 'a'; c <= 'z'; c++) { // 26 times
                        word[i] = c;
                        if (vis.count(word)) { // O(1)
                            if (word == endWord) return result;
                            vis.erase(word);
                            v2.push_back(word);
                        }
                    }
                    word[i] = tmp;
                }
            }
            v1.swap(v2);
        }
        return 0;
    }
};