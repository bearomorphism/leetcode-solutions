class Solution {
public:
    int minimumMoves(string s) {
        int i = 0;
        int n = s.length();
        int ret = 0;
        while (i < n) {
            while (i < n && s[i] == 'O') i++;
            if (i < n) ret++;
            for (int j = i; j < min(n, i + 3); j++) {
                s[j] = 'X';
            }
            i += 3;
        }
        return ret;
    }
};