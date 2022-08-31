class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ret;
        for (char i = s[0]; i <= s[3]; i++) {
            for (char j = s[1]; j <= s[4]; j++) {
                ret.push_back({i, j});
            }
        }
        return ret;
    }
};