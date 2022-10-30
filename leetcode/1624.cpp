class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v(26, -1);
        int ret = -1;
        for (int i = 0; i < s.length(); i++) {
            if (v[s[i] - 'a'] != -1) {
                ret = max(ret, i - v[s[i] - 'a'] - 1);
            } else {
                v[s[i] - 'a'] = i;
            }
        }
        return ret;
    }
};