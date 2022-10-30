class Solution {
public:
    bool detectCapitalUse(string word) {
        int l = word.length();
        if (isupper(word[0])) {
            if (l == 1) return true;
            if (isupper(word[1])) {
                for (int i = 2; i < l; i++) {
                    if (!isupper(word[i])) return false;
                }
                return true;
            } else {
                for (int i = 2; i < l; i++) {
                    if (isupper(word[i])) return false;
                }
                return true;
            }
        } else {
            for (int i = 1; i < l; i++) {
                    if (isupper(word[i])) return false;
                }
                return true;
        }
    }
};