class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i - 1] > s[i]) return false;
        }
        return true;
    }
};