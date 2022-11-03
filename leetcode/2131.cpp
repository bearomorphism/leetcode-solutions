class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> u;
        int result = 0;
        for (auto &s: words) {
            if (u[s] > 0) {
                u[s]--;
                result += 4;
            } else {
                u[string(s.rbegin(), s.rend())]++;
            }
        }
        for (auto &[word, cnt]: u) {
            if (word[0] == word[1] && cnt > 0) return result + 2;
        }
        return result;
    }
};

