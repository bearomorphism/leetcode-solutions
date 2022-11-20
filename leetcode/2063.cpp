class Solution {
public:
    long long countVowels(string s) {
        long long result = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                result += (long long)(i + 1) * (n - i);
            }
        }
        return result;
    }
};