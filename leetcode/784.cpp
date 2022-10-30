class Solution {
private:
    void dfs(string &s, vector<string> &ret, int idx) {
        if (idx == s.length()) {
            ret.push_back(s);
            return;
        }
        if (isalpha(s[idx])) {
            s[idx] = toupper(s[idx]);
            dfs(s, ret, idx + 1);
            s[idx] = tolower(s[idx]);
            dfs(s, ret, idx + 1);
        } else {
            dfs(s, ret, idx + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ret;
        dfs(s, ret, 0);
        return ret;
    }
};