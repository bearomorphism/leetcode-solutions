class Solution {
public:
    vector<vector<string>> partition(string s) {
        result_ = {};
        par_ = {};
        s_ = s;
        dfs(0);
        return result_;
    }
private:
    vector<vector<string>> result_;
    vector<string> par_;
    string s_;
    void dfs(int idx) {
        if (idx == s_.length()) {
            result_.push_back(par_);
            return;
        }
        for (int i = idx; i < s_.length(); i++) {
            string t = s_.substr(idx, i - idx + 1);
            if (helper(t)) {
                par_.push_back(t);
                dfs(i + 1);
                par_.pop_back();
            }
        }
    }
    bool helper(string s) {
        int n = s.length() / 2;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[s.length() - i - 1]) return false;
        }
        return true;
    }
};