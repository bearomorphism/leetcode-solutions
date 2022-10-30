class Solution {
public:
    int numSteps(string s) {
        int ret = 0;
        int i = s.length() - 1;
        while (i >= 0) {
            if (s[i] == '1') {
                if (i == 0) return ret;
                int j = i;
                while (j >= 0 && s[j] == '1') {
                    s[j] = '0';
                    j--;
                }
                if (j >= 0) s[j] = '1';
            } else {
                i--;
            }
            ret++;
        }
        return ret;
    }
};