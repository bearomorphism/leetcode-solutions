class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = 'a';
                while (i > 0 && s[i - 1] == s[i] || i < n - 1 && s[i + 1] == s[i]) s[i]++;
            }
        }
        return s;
    }
};