class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int result = n;
        for (int i = 0; i < n; i++) {
            for (int j = 1; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) result++;
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; j++) result++;
        }
        return result;
    }
};